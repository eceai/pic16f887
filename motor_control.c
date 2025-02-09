#include<pic.h>
#define RS RE0
#define RW RE1
#define EN RE2
int k=0x84;
void delay (int s)
{
while(s--);
}
// PULSE Function
void pulse()
{
EN=1;
delay(1000);
EN=0;
delay(1000);
}
void display()
{
RS=0;
RW=0;
PORTD=0X38;

}
void on()
{
RS=0;
RW=0;
PORTD=0X0E;
pulse();
}
void address(char k)
{
RS=0;
RW=0;
PORTD=k;
pulse();
}
void data(char s)
{
RS=1;
RW=0;
PORTD=s;
pulse();
}
void main()
{
TRISA=0x70;
PORTA=0x00;
TRISD=0X00;
PORTD=0X00;
TRISC=0X00;
PORTC=0X00;
TRISE=0X00;
PORTE=0X00;
ANSEL=0X00;
ANSELH=0X00;
display();
on();
address(k);
data('M');
address(k+1);
data('O');
address(k+2);
data('T');
address(k+3);
data('O');
address(k+4);
data('R');
address(k+5);
data(0);
address(k+6);
data('O');
address(k+7);
data('F');
address(k+8);
data('F');
while(1)
{
address(k);
RA0=1;RA1=0;RA2=0;RA3=0;
if(RA4==1)
{
RC0=1;RC1=0;
address(k);
data('M');
address(k+1);
data('O');
address(k+2);
data('T');
address(k+3);
data('O');
address(k+4);
data('R');
address(k+5);
data(0);
address(k+6);
data('F');
address(k+7);
data('W');
address(k+8);
data('D');
while(RA4==1);
}

if(RA5==1)
{
RC0=0;RC1=1;
address(k);
data('M');
address(k+1);
data('O');
address(k+2);
data('T');
address(k+3);
data('O');
address(k+4);
data('R');
address(k+5);
data(0);
address(k+6);
data('R');
address(k+7);
data('E');
address(k+8);
data('V');
while(RA5==1);
}
if(RA6==1)
{
RC0=0;RC1=0;
address(k);
data('M');
address(k+1);
data('O');
address(k+2);
data('T');
address(k+3);
data('O');
address(k+4);
data('R');
address(k+5);
data(0);
address(k+6);
data('O');
address(k+7);
data('F');
address(k+8);
data('F');
while(RA6==1);
}
}
}

RESULT video

https://github.com/user-attachments/assets/7c407740-663a-4610-9854-21ebbf2ffd19
