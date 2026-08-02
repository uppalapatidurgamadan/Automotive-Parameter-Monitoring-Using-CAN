#include <LPC21xx.h>         // LPC21xx register definitions
#include "interrupts.h"      // External interrupt definitions

// Flag variables used to control indicator ON/OFF state
volatile int flag1 = 1;
volatile int flag2 = 1;

// Indicator status variables
volatile int blinkright;     // Right indicator status
volatile int blinkleft;      // Left indicator status

//-------------------- EINT0 ISR --------------------//
// Triggered when Left Indicator Switch is pressed
void eint0_isr(void) __irq
{
    if(flag1)
    {
        blinkleft = 1;       // Enable left indicator
        blinkright = 0;      // Disable right indicator

        flag1 = 0;           // Toggle state
        flag2 = 1;
    }
    else
    {
        blinkright = 0;      // Turn OFF right indicator
        blinkleft = 0;       // Turn OFF left indicator

        flag1 = 1;           // Reset flags
        flag2 = 1;
    }

    EXTINT = (1 << 0);       // Clear EINT0 interrupt flag
    VICVectAddr = 0;         // Notify end of ISR to VIC
}

//-------------------- EINT1 ISR --------------------//
// Triggered when Right Indicator Switch is pressed
void eint1_isr(void) __irq
{
    if(flag2)
    {
        blinkright = 1;      // Enable right indicator
        blinkleft = 0;       // Disable left indicator

        flag2 = 0;           // Toggle state
        flag1 = 1;
    }
    else
    {
        blinkright = 0;      // Turn OFF right indicator
        blinkleft = 0;       // Turn OFF left indicator

        flag2 = 1;           // Reset flags
        flag1 = 1;
    }

    EXTINT = (1 << 1);       // Clear EINT1 interrupt flag
    VICVectAddr = 0;         // Notify end of ISR to VIC
}

//-------------------- Enable External Interrupts --------------------//
// Configures EINT0 and EINT1 and registers their ISRs
void Enable_EINTs(void)
{
    // Configure P0.3 as EINT1 function
    PINSEL0 = ((PINSEL0 & ~(3 << 6)) | (3 << 6));

    // Configure P0.16 as EINT0 function
    PINSEL1 = ((PINSEL1 & ~(3 << 0)) | (1 << 0));

    // Enable EINT0 and EINT1 interrupts in VIC
    VICIntEnable = ((1 << EINT0_VIC_CHNO) |
                    (1 << EINT1_VIC_CHNO));

    // Configure Vector Slot 0 for EINT0
    VICVectCntl0 = (1 << 5) | EINT0_VIC_CHNO;
    VICVectAddr0 = (unsigned int)eint0_isr;

    // Configure Vector Slot 1 for EINT1
    VICVectCntl1 = (1 << 5) | EINT1_VIC_CHNO;
    VICVectAddr1 = (unsigned int)eint1_isr;

    // Configure both interrupts as edge-triggered
    EXTMODE = ((1 << 0) | (1 << 1));
}
