#include <avr/io.h>
#define F_CPU 8000000UL
#include "std_macros.h"

void ADC_initialize(void)
{
	CLR_BIT(ADMUX,MUX0);
	CLR_BIT(ADMUX,MUX1);
	CLR_BIT(ADMUX,MUX2);
	
	CLR_BIT(ADMUX,ADLAR);
	
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	
	CLR_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	SET_BIT(ADCSRA,ADEN);
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned short ADC_read(void)
{
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADIF)==0);
	SET_BIT(ADCSRA,ADIF);
	
	unsigned short returned_value;
	returned_value=ADCL;
	returned_value|=(ADCH<<8);
	
	return returned_value;
}	
	
	