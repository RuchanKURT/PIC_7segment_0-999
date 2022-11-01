#include <16f877a.h>
#fuses HS,NOWDT
#use delay(clock=20000000)

int i;
int sayi = 0;
int birler,onlar,yuzler;
void bin2dec(int);
int bcd2_7seg(int);

void main()
{
set_tris_b(0x00);
set_tris_c(0x00);
set_tris_d(0xFF);
output_b(0x00);
output_c(0x00);
output_d(0x00);

while(1){
sayi = input_d();
sayi = sayi & 0b1111111111;

bin2dec(sayi);
output_c(0b110);
output_b(bcd2_7seg(birler));
delay_ms(5);
bin2dec(sayi);
output_c(0b101);
output_b(bcd2_7seg(onlar));
delay_ms(5);
bin2dec(sayi);
output_c(0b011);
output_b(bcd2_7seg(yuzler));
delay_ms(5);
}
}

void bin2dec(int input){
   birler = input%10;
   onlar = (input/10)%10;
   yuzler = (input/100)%10;
}

int bcd2_7seg(int num){
   switch(num)
   {
   case 0: return 0x3F;
   case 1: return 0x06;
   case 2: return 0x5B;
   case 3: return 0x4F;
   case 4: return 0x66;
   case 5: return 0x6D;
   case 6: return 0x7C;
   case 7: return 0x07;
   case 8: return 0x7F;
   case 9: return 0x6F;
   }
}
