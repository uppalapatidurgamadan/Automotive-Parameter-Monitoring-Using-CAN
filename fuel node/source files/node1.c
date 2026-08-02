#include <LPC21xx.h>        // LPC21xx register definitions
#include "adc.h"            // ADC function declarations
#include "adc_defines.h"    // ADC-related macros and constants
#include "delay.h"          // Delay function declarations
#include "can.h"            // CAN driver functions and frame structure
#include "lcd.h"            // LCD functions (if required)

int adcDval;                // Stores raw ADC value
float eAR;                  // Stores equivalent analog voltage

CANF txF;                   // CAN transmit frame structure
volatile int t;             // Stores calculated fuel percentage

int main()
{
    Init_CAN1();            // Initialize CAN1 peripheral

    Init_ADC(AIN1_0_27);    // Initialize ADC channel connected to fuel sensor

    // Configure CAN transmit frame
    txF.ID = 2;             // CAN message identifier
    txF.bfv.RTR = 0;        // Data frame (not Remote Frame)
    txF.bfv.DLC = 1;        // Transmit 1 byte of data

    while(1)
    {
        // Read ADC value and equivalent voltage
        Read_ADC(1, &eAR, &adcDval);

        // Limit ADC value within calibrated range
        if(adcDval > MAX_VAL)
            adcDval = MAX_VAL;
        else if(adcDval < MIN_VAL)
            adcDval = MIN_VAL;

        // Convert ADC value into fuel percentage (0–100%)
        t = (((adcDval - MIN_VAL) * 100) / (MAX_VAL - MIN_VAL));

        // Store fuel percentage in CAN data field
        txF.Data1 = t;

        // Transmit fuel percentage over CAN bus
        CAN1_Tx(txF);

        // Update every 500 ms
        delay_ms(500);
    }
}
