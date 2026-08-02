#include <LPC21xx.h>      // LPC21xx register definitions
#include "delay.h"        // Delay function declarations
#include "can.h"          // CAN driver functions and frame structure

CANF rxF;                 // CAN receive frame structure

int main()
{
    unsigned char n;      // Variable used for LED shifting pattern

    Init_CAN1();          // Initialize CAN1 peripheral

    IODIR0 |= 0xFF;       // Configure P0.0–P0.7 as output (LEDs)
    IOSET0 = 0xFF;        // Turn OFF all LEDs (active-low LEDs)

    while(1)
    {
        // Check whether a CAN message has been received
        if(C1GSR & 0x01)
        {
            CAN1_Rx(&rxF);      // Receive CAN frame

            C1CMR = 0x04;       // Release receive buffer

            // Process only messages with CAN ID = 1
            if(rxF.ID == 1)
            {
                //---------------- Left Indicator ----------------//
                if(rxF.Data1 == 1)
                {
                    while(1)
                    {
                        n = 0x01;              // Start from LED0

                        while(n)
                        {
                            IOCLR0 = n;        // Turn ON current LED
                            delay_ms(200);     // LED ON delay

                            n = n << 1;        // Move to next LED

                            // Check for new CAN command
                            if(C1GSR & 1)
                            {
                                CAN1_Rx(&rxF);

                                // Exit animation if command changes
                                if(rxF.ID == 1)
                                    if(rxF.Data1 != 1)
                                        break;
                            }
                        }

                        IOSET0 = 0xFF;         // Turn OFF all LEDs
                        delay_ms(200);

                        // Stop animation if another command is received
                        if(rxF.ID == 1)
                            if(rxF.Data1 != 1)
                                break;
                    }
                }

                //---------------- Right Indicator ----------------//
                else if(rxF.Data1 == 2)
                {
                    while(1)
                    {
                        n = 0x80;              // Start from LED7

                        while(n)
                        {
                            IOCLR0 = n;        // Turn ON current LED
                            delay_ms(200);     // LED ON delay

                            n = n >> 1;        // Move to previous LED

                            // Check for new CAN command
                            if(C1GSR & 1)
                            {
                                CAN1_Rx(&rxF);

                                // Exit animation if command changes
                                if(rxF.ID == 1)
                                    if(rxF.Data1 != 2)
                                        break;
                            }
                        }

                        IOSET0 = 0xFF;         // Turn OFF all LEDs
                        delay_ms(200);

                        // Stop animation if another command is received
                        if(rxF.ID == 1)
                            if(rxF.Data1 != 2)
                                break;
                    }
                }

                //---------------- No Indicator ----------------//
                else
                {
                    IOSET0 = 0xFF;             // Turn OFF all LEDs
                }
            }
        }
    }
}
