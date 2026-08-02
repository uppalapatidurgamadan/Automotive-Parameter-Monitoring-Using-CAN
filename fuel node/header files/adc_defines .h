#define FOSC 	12000000  // Crystal oscillator frequency (12 MHz)
#define CCLK 	(FOSC*5)   // CPU Clock = FOSC × PLL Multiplier (12 MHz × 5 = 60 MHz)
#define PCLK 	(CCLK/4)    // Peripheral Clock = CPU Clock / 4 (60 MHz / 4 = 15 MHz)
#define ADCCLK 	3000000   // Required ADC Clock Frequency (Maximum recommended: 4.5 MHz)
                           // Using 3 MHz for reliable ADC operation
#define CLKDIV 	((PCLK/ADCCLK)-1)   // ADC Clock Divider
                                    // ADC Clock = PCLK / (CLKDIV + 1)

#define CLKDIV_BITS 8      // Clock Divider starts from Bit 8 in ADCR register
#define PDN_BIT		21       // Power Down (PDN) bit position
                                // Set to 1 to enable ADC
#define START_BIT	24         // Start Conversion bit position

#define DIGITAL_CONV_DATA 	6   // ADC conversion result starts from Bit 6
#define DONE_BIT			31         // DONE bit indicates conversion completion

#define AIN1_0_27 24           // P0.27 configured as ADC Channel 1 (AIN1)


#define MAX_VAL	340         // ADC value when fuel tank is full
#define MIN_VAL	90          // ADC value when fuel tank is empty
