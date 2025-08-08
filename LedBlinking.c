void main() {
TRISD=0X00;
while(1){
   PORTD.F2=1;
   Delay_ms(2000);
   PORTD.F2=0;
   Delay_ms(2000);
}
}