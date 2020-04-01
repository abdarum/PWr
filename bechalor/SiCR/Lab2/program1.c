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
   ThreadCtl( _NTO_TCTL_IO, 0 );
   base = mmap_device_io(16,ADRB);
   printf("Test wejsc/wyjsc cyfrowych\n");
   // Test wejsc  cyfrowych
   i= 0;
   do {
      val1 = dinp(1);
      printf(" wejscie1 %02X \n",val1);
      usleep(50000);
      dout(2,val1);
//      i=i+1%256;
//      dout(2,i);

   } while(1);
}
