#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"
#include "SEVENSEGMENT.h"
#include "EEPROM.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "ADC.h"
#include "TIMER0.h"

volatile unsigned int counter=0;

int main()
{
	TIMER0_initialize();
	LCD_initialize();
	LCD_writecmd(0x0c);
	LED_initialize('c',0);
	LED_initialize('c',1);
	LED_initialize('d',7);
	unsigned char red=15;
	unsigned char yellow=6;
	unsigned char green=15;
	
	while(1)
	{
		LED_on('c',0);
		LCD_writestring("TIME: 15 S");
		while(green>0)
		{
			if (counter>=50)
			{
				green--;
				LCD_movecursor(1,7);
				LCD_writecharacter((green/10)+48);
				LCD_writecharacter((green%10)+48);
				counter=0;
			}
		}

		LED_off('c',0);
		LED_on('c',1);
		LCD_clearscreen();
		LCD_writestring("TIME: 06 S");
		
		while(yellow>0)
		{
			if (counter>=50)
			{
				yellow--;
				LCD_movecursor(1,7);
				LCD_writecharacter((yellow/10)+48);
				LCD_writecharacter((yellow%10)+48);
				counter=0;
			}
		}
		
		LED_off('c',1);
		LED_on('d',7);
		LCD_clearscreen();
		LCD_writestring("TIME: 15 S");
		
		while(red>0)
		{
			if (counter>=50)
			{
				red--;
				LCD_movecursor(1,7);
				LCD_writecharacter((red/10)+48);
				LCD_writecharacter((red%10)+48);
				counter=0;
			}
		}
		LED_off('d',7);
		green=15;
		yellow=6;
		red=15;
		LCD_clearscreen();
	}
}


ISR(TIMER0_COMP_vect)
{
	counter++;
}