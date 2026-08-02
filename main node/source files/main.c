#include <LPC21xx.h>        // LPC21xx register definitions
#include "lcd.h"            // LCD driver functions
#include "delay.h"          // Delay functions
#include "types.h"          // User-defined data types
#include "defines.h"        // Utility macros
#include "can.h"            // CAN driver functions
#include "ds18b20.h"        // DS18B20 temperature sensor functions
#include "interrupts.h"     // External interrupt functions

CANF txF;                   // CAN transmit frame
CANF rxF;                   // CAN receive frame

// Variables updated by external interrupt ISRs
extern int blinkleft;
extern int blinkright;

int main()
{
    int temp, fuel = 0;

    // Initialize peripherals
    Init_CAN1();            // Initialize CAN controller
    Init_LCD();             // Initialize LCD
    Enable_EINTs();         // Enable external interrupts

    // Configure CAN transmit frame
    txF.ID = 1;             // Main node CAN ID
    txF.bfv.RTR = 0;        // Data frame
    txF.bfv.DLC = 1;        // One byte of data

    while(1)
    {
        //---------------- Display Project Title ----------------//
        cmdLCD(0x80);                   // First line
        stringLCD("<<< DASH BORD >>>");

        //---------------- Read & Display Temperature ----------------//
        cmdLCD(0x94);                   // Third line
        stringLCD("ENGINE TEMP:");

        temp = ReadTemp();              // Read DS18B20 temperature

        if(temp == -1)
        {
            stringLCD("TEMP ERR");      // Display error if sensor fails
        }
        else
        {
            integerLCD(temp >> 4);      // Convert raw data to Celsius
            charLCD(223);               // Degree symbol
            stringLCD("C    ");
        }

        //---------------- Display Indicator Symbols ----------------//
        cmdLCD(0xD4);
        stringLCD("INDICATOR:");

        // Load custom characters into LCD CGRAM
        cmdLCD(0x48);
        LIndicatorDisp();               // Left indicator symbol

        cmdLCD(0x40);
        RIndicatorDisp();               // Right indicator symbol

        // Display left and right indicator icons
        cmdLCD(0xD4 + 11);
        charLCD(1);

        cmdLCD(0xD4 + 13);
        charLCD(0);

        //---------------- Load Fuel Level Symbols ----------------//
        cmdLCD(0x50);
        fuel1();                        // 25% fuel symbol

        cmdLCD(0x58);
        fuel2();                        // 50% fuel symbol

        cmdLCD(0x60);
        fuel3();                        // 75% fuel symbol

        cmdLCD(0x68);
        fuel4();                        // 100% fuel symbol

        //---------------- Left Indicator ----------------//
        if(blinkleft)
        {
            txF.Data1 = 1;              // Send Left Indicator command
            CAN1_Tx(txF);

            // Blink left indicator on LCD
            cmdLCD(0xD4 + 11);
            charLCD(1);
            delay_ms(500);

            cmdLCD(0xD4 + 11);
            charLCD(' ');
            delay_ms(500);
        }

        //---------------- Right Indicator ----------------//
        else if(blinkright)
        {
            txF.Data1 = 2;              // Send Right Indicator command
            CAN1_Tx(txF);

            // Blink right indicator on LCD
            cmdLCD(0xD4 + 13);
            charLCD(0);
            delay_ms(500);

            cmdLCD(0xD4 + 13);
            charLCD(' ');
            delay_ms(500);
        }

        //---------------- Indicator OFF ----------------//
        else
        {
            txF.Data1 = 3;              // No indicator active
            CAN1_Tx(txF);
        }

        //---------------- Receive Fuel Data ----------------//
        if(C1GSR & 1)                   // Check if CAN message received
        {
            CAN1_Rx(&rxF);

            // Accept fuel data only from Fuel Node
            if(rxF.ID == 2)
            {
                fuel = rxF.Data1;
            }
        }

        //---------------- Display Fuel Level ----------------//
        cmdLCD(0xC0);
        stringLCD("FUEL:");

        // Display fuel bar according to percentage
        if(fuel <= 25)
        {
            charLCD(2);
            charLCD(' ');
            charLCD(' ');
            charLCD(' ');
        }
        else if(fuel <= 50)
        {
            charLCD(2);
            charLCD(3);
            charLCD(' ');
            charLCD(' ');
        }
        else if(fuel <= 75)
        {
            charLCD(2);
            charLCD(3);
            charLCD(4);
            charLCD(' ');
        }
        else
        {
            charLCD(2);
            charLCD(3);
            charLCD(4);
            charLCD(5);
        }

        // Display fuel percentage
        cmdLCD(0xC9);
        integerLCD(fuel);
        stringLCD("%  ");

        // Small refresh delay
        delay_ms(10);
    }
}
