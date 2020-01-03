#include <sys/neutrino.h>
#include <stdio.h>
#include <hw/inout.h>

#define ADRB 0x300
#define WE 1
#define WY 2
#define DIOL        3
#define DIOH      11

static int base = ADRB;

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

main() {
   int val1,val2, chn ;
   unsigned char i = 0;
   int tab[8][2]={
		   {1,1},
		   {2,2},
		   {4,3},
		   {8,4},
		   {16,1},
		   {32,2},
		   {64,3},
		   {128, 4}
   };
   ThreadCtl( _NTO_TCTL_IO, 0 );
   base = mmap_device_io(16,ADRB);
   printf("Test wejsc/wyjsc cyfrowych\n");
   // Test wejsc  cyfrowych
   i= 0;
   do {
      val1 = dinp(1);
      printf(" wejscie1 %02X \n",val1);
	  dout(2, tab[i][0]);
	  sleep(tab[i][1]);
//	  usleep(tab[i][1]*500000);
//	  int we = 1;
	  int we = dinp(1);
	  //if(i == 1 && we == 1 )
	  while(we != 1 )
	  {
		  we = dinp(1);
	  }
//      dout(2,val1);
//      usleep(50000);
//      i=i+1%256;
//      dout(2,i);
      i = (i + 1) % 8;
   } while(1);
}
