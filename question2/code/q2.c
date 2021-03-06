/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : question2
Version : 
Date    : 12/10/2020
Author  : Fariba Saadati
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
 
// Declare your global variables here

void main(void)
{
// Declare your local variables here
     
    unsigned char a = 0b00000001;     //one LED is on
    unsigned char b = 0b00000011;     //two LED is on at the same time
    unsigned char c = 0b10000000;     //inverse
    unsigned char d = 0b11000000;     //inverse
    int i; 
    
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=P 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (1<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
 

       
while (1)
      {                            
      // Place your code here   
         PORTB=0x00;
         if (PINA.0 == 0)      //push button
         {
             for (i=0; i<= 7;i=i+1)
             {
             PORTB = a;
             a = a<<1;   //shift a to left
             delay_ms(50);
             PORTB = b;
             b= b<<1;      //shift b to left
             delay_ms(25);
                  }  
                  
             for (i=0;i<=7;i=i+1)
             {   
                  
                PORTB = c;
                c = c>>1;  //shift c to right
                delay_ms(50);
                PORTB = d;
                d = d>>1;     //shift right
                delay_ms(25);
             } 
                  
              }
      }
}
