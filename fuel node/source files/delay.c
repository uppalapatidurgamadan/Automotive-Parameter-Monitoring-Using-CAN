#include "types.h"
void delay_us(u32 tdly){      // Function to generate a delay in microseconds
	tdly*=12;                 // Convert microseconds into loop count
                              // (Assuming 12 MHz CPU clock)
	while(tdly--);             // Wait until loop count becomes zero
}
void delay_ms(u32 tdly){
	tdly*=12000;              // Convert milliseconds into loop count
                              // (1 ms = 12000 clock cycles at 12 MHz)

	while(tdly--);              // Wait until loop count becomes zero
} 
void delay_s(u32 tdly){
	tdly*=12000000;            // Convert seconds into loop count
                              // (1 s = 12,000,000 clock cycles at 12 MHz)

	while(tdly--);                // Wait until loop count becomes zero
}
