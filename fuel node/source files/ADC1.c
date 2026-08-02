#include <LPC21xx.h>           // LPC2129 Special Function Register definitions
#include "delay.h"             // Delay function declarations
#include "lcd.h"               // LCD function declarations (used in other ADC-related functions)
#include "adc_defines.h"        // ADC configuration macros and bit definitions

void Init_ADC(unsigned char pin){    //Initializes the ADC for the selected analog pin
	PINSEL1&=~(1<<pin);                  // Clear the PINSEL bit
	PINSEL1|=(1<<pin);                       // Configure the pin as ADC input
	ADCR=((1<<PDN_BIT)|(CLKDIV<<CLKDIV_BITS));          // Enable ADC and set ADC clock divider
}

void Read_ADC(int chNo,float *eAR,int *adcDval){         //  Starts ADC conversion and reads the result.
	ADCR&=0xFFFFFF00;                                      // Clear previous channel selection
	ADCR|=((1<<START_BIT)|(1<<chNo));                          // Select ADC channel and start conversion
	delay_us(3);                                                 // Small delay for conversion to begin
	while(((ADDR>>DONE_BIT)&1)==0);                           // Wait until ADC conversion is complete
	ADCR&=~(1<<START_BIT);                                     // Stop ADC conversion
	*adcDval=((ADDR>>DIGITAL_CONV_DATA)&1023);                 // Read 10-bit digital ADC result
	*eAR=*adcDval*(3.3/1023);                                   // Convert digital value into corresponding analog voltage
}
