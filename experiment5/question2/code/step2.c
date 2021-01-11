/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : task5-question2
Version : 
Date    : 1/8/2021
Author  :  Fariba Saadati
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>

int count=0; 
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0x38;
// Place your code here
count++;

  if (count==100){
    if (PINC.2 == 0 ){      //rotete clockwise
         
            //step1
            PORTA=0x09;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
             
            //step2
            PORTA=0x0a;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
              
           //step3
            PORTA=0x06;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
            
          //step4
            PORTA=0x05;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
             
   }  
   
   
   if (PINC.2 == 1){       //rotate anticlockwise

            PORTA=0x05;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
             
            //step2
            PORTA=0x06;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
              
           //step3
            PORTA=0x0a;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);
            
          //step4
            PORTA=0x09;
            delay_ms(5);
            PORTA=0x00;
            delay_ms(5);

    }
   
          
   count=0;
  } 
 
  TCNT0= 0x38;                
}
 
void main(void)
{

DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0); 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (1<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 4000.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
// Timer Period: 0.05 ms
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x38;
OCR0=0x00;
 
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
 
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

#asm("sei")

while (1)
      {
      // Place your code here
        
      }
}
 
 