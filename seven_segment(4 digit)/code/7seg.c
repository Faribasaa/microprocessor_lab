/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : project2 - counter with 7-segment 
Version : 2
Date    : 12/20/2020
Author  : Fariba Saadati
Company : kharazmi university
Comments: (showing by overflow timer0)


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
 
#define DIG_1   0b11111110
#define DIG_2   0b11111101
#define DIG_3   0b11111011
#define DIG_4   0x11110111
unsigned char numbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
int digits[] = {DIG_1, DIG_2, DIG_3, DIG_4};
int count = -1;
int counter,D1,D2,D3,D4;  
     
 
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0x64;
counter ++;

if (counter ==3){
   
    //digit1
    D1 = count % 10;
    PORTC = digits[0];
    PORTD = numbers[D1];
    delay_ms(75); 
    PORTC=0xFF;
    PORTD=0x00;
     
    //digit2             
    D2 = (count%100) / 10;
    PORTC = digits[1];
    PORTD = numbers[D2]; 
    delay_ms(75);
    PORTC=0xFF;
    PORTD=0x00;
      
    //digit3
    D3 = count% 1000;
    PORTC = digits[2];
    PORTD = numbers[D3];
    delay_ms(75);  
    PORTC=0xFF;
    PORTD=0x00;
      
    //digit4
    D4 = (count %1000) /100;
    PORTC = digits[3];
    PORTD = numbers[D4]; 
    delay_ms(75);
    PORTC=0xFF;
    PORTD=0x00;
      
    
     counter=0;	
            
	}    
}
 


// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Reinitialize Timer1 value
TCNT1H=0xBDC >> 8;
TCNT1L=0xBDC & 0xff;
   
      if (count < 10000) {
           count++;
		} 
        
	  else{
	        count = 0;
	      }
	       
   }
 


void main(void)
{
 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
 
DDRD=(0<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
  
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x64;
OCR0=0x00;
 
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x0B;
TCNT1L=0xDC;

TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here

      }
}
