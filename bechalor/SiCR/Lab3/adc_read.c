//-------------------------------------------------------------------------
// Karta PCM 3817H - obsluga wejsc AD i DI w trybie pollingu - wzor
// (C) J. Ulasiewicz 2010
#include <stdlib.h>
#include <stdio.h>
// #include "pcm3817.h"

#include <sys/neutrino.h>
#include <hw/inout.h>
#define BASE 0x300
#define ADL         0
#define ADH         1
#define RANGE     1   // Wzmocnienie kanalu
#define MUXR      2   // Zakresy pomiarowe
#define DIOL        3
#define STATR     8
#define CONTR    9
#define TIMR      10
#define DIOH      11
#define COUNT0  12
#define COUNT1  13
#define  COUNT2 14
#define  COUNTC 15

#define ADRB 0x300
static int base = ADRB;


card_init(int from, int to, unsigned char zakres) {
// Inicjalizacja karty
// from - kanal poczatkowy, to kanal koncowy
// zakresy pomiarowe  0-10 V -> 4, 0-5V -> 5, 0-2.5 -> 6, 0-1.25 -> 7
   unsigned char val,i;
   printf("inicjacja karty kanaly od %d  do %d\n",from,to);
   out8(base + CONTR,  0x00);
   val =  in8(base + CONTR);
   if(val != 0x00) {
     printf("Blad inicjalizacji\n");
     exit(0);
   }
   // Ustawienie kan. pocz i konc
   out8(base + MUXR,  (to << 4) | from);
   out8(base + TIMR,  0x00);
   // Odczyt rejestru MUX ----
   val =  in8(base + MUXR);
   // Ustawienie zakresu pomiarowego kanalow
   for(i = from; i<= to; i++) {
      out8(base + MUXR,  i);
      out8(base + RANGE,zakres);
   }
   // Ustawienie kan. pocz i konc
   out8(base + MUXR,  (to << 4) | from);
   val =  in8(base + MUXR);
   printf("MUX = %2X\n",val);

}


void dout(int num, unsigned char val) {
// Sterowanie portem wyjsc cyfrowych
// num - port (1,2) , val - wartosc (0 - 255)
  if(num <= 1) {
    out8(base + DIOL, val);
  } else {
    out8(base + DIOH, val);
  }
 }


  unsigned char dinp(int num) {
  // Odczyt portu wejsc cyfrowych
  // // num - port (1,2)
  if(num <= 1) {
    return( in8(base + DIOL));
  } else {
   return( in8(base + DIOH));
  }
 }


int aread(unsigned int *chan) {
  unsigned int stat,al,ah;
  unsigned int x,xh,xl;
  int i = 0;
  // Start konwersji

  out8(base+0,1);

   do {
       // Odczyt statusu EOC
       stat =  in8(base+8);
       stat = stat & (1<<7);
       i++;
       if(i >= 0xFFFF) return(-1);
   } while(stat);

   al = in8(base+0);
   ah = in8(base+1);
   xh = ah << 4;
   xl  = al >> 4;
   // printf("A1: %04X  A0: %4X i= %d \n",ah,al,i);
   *chan = al & 0x0F;
    x = xl + xh;

    // printf("chan %d %04X %04X  val %d %04X \n",*chan, xh, xl, x,x);
    return(x);
}

main() {
   int val,val2, chn,j,count=0 ;
   unsigned char d1,d2, i = 0;
   printf("Program startuje \n");
   ThreadCtl( _NTO_TCTL_IO, 0 );
   base = mmap_device_io(16,ADRB);
   card_init(0,3,5);
   printf("wersja 6\n");
   sleep(1);

   do {
      for(j=0; j<4; j++) {
           val = aread(&chn);
           printf(" %d - %d ",chn,val);
           if (chn == 0){
        	   val2 = val;
			   val2 = val2/512;
//			   if(val > 3950){
//				   val2 = 8;
//			   }
			   int out_led = (0xFF<<val2);
			   dout(2,out_led);

           }
      }
      d1 = dinp(1);
      printf("we1 %2X  \n",d1);
      sleep(1);
      // sterowanie wyjsciami cyfrowymi
      i++;
    } while( count++ < 100);
}
