/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project :  task3 - question2
Version : 
Date    : 12/26/2020
Author  :  Fariba Saadati
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
#include <alcd.h>


void main(void)
{
int i;
char a;
char alpha[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 

DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
lcd_init(16);

while (1)
      { 
     
       for (i=0;i<27;i++){ 
           if (i <16){
           lcd_gotoxy(i,0);
           lcd_putchar(alpha[i]);    
        }
         
        else {
           a=alpha[i];
           lcd_gotoxy((i-16),1); 
           lcd_putchar(a);
          }
          
          delay_ms(200);
       }
        
    }
       
}
