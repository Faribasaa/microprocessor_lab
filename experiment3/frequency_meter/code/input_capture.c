/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : task3 - question3
Version : 
Date    : 12/27/2020
Author  : Fariba Saadati
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>
#include <stdio.h>
#include <alcd.h>
 
unsigned int start_time,stop_time,start_f_time,period;
long frequency;
char str[16];


void main(void)
{
  
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

 

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 8000.000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Rising Edge
// Timer Period: 8.192 ms
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (1<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);
 
// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTC Bit 0
// RD - PORTC Bit 1
// EN - PORTC Bit 2
// D4 - PORTC Bit 4
// D5 - PORTC Bit 5
// D6 - PORTC Bit 6
// D7 - PORTC Bit 7
// Characters/line: 16
lcd_init(16);

while (1)
      {
      TCCR1A = 0;
      TCNT1=0;
      TIFR = (1<<ICF1);      
      TCCR1B = 0x41; 
       
        while ((TIFR&(1<<ICF1)) == 0);
        start_time = (256*ICR1H+ICR1L);         
        TIFR = (1<<ICF1);     
                
        TCCR1B = 0x01;    
        while ((TIFR&(1<<ICF1)) == 0);
        start_f_time = (256*ICR1H+ICR1L);          
        TIFR = (1<<ICF1);     
                
        TCCR1B = 0x41;
        while ((TIFR&(1<<ICF1)) == 0);
        stop_time = (256*ICR1H+ICR1L); 
        TIFR = (1<<ICF1);

        TCCR1B = 0;
		
		if(start_time < stop_time)
		{
			period = stop_time - start_time;
			
			frequency= 8000000UL/period;
            sprintf(str,"%d (Hz)", (int)frequency);
			
            lcd_clear();
            lcd_gotoxy(2,0);
			lcd_puts("Frequency :");
            lcd_gotoxy(4,1);
            lcd_puts(str);
		} 
        
        delay_ms(500); 

      }
}
