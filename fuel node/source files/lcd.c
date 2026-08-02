#include <LPC21xx.h>      // LPC21xx register definitions
#include "delay.h"        // Delay function declarations
#include "types.h"        // User-defined data types
#include "defines.h"      // Bit manipulation macros
#include "lcd.h"          // LCD function declarations

#define CAT 0xFF          // LCD data pins (8-bit mode)
#define RS  5             // Register Select pin connected to P0.5
#define RW  7             // Read/Write pin connected to P0.7
#define EN  6             // Enable pin connected to P0.6

//-------------------- LCD Initialization --------------------//
void Init_LCD(void)
{
    // Configure LCD data pins and control pins as output
    IODIR0 |= ((CAT << 8) | (1 << RS) | (1 << RW) | (1 << EN));

    // LCD initialization sequence
    delay_ms(20);         // Wait for LCD power stabilization

    cmdLCD(0x30);         // Function set
    delay_ms(10);

    cmdLCD(0x30);         // Function set
    delay_ms(1);

    cmdLCD(0x30);         // Function set
    delay_ms(1);

    cmdLCD(0x38);         // 8-bit mode, 2-line display, 5x7 font
    cmdLCD(0x10);         // Cursor move command
    cmdLCD(0x01);         // Clear display
    cmdLCD(0x06);         // Cursor auto-increment
    cmdLCD(0x0C);         // Display ON, Cursor OFF
}

//-------------------- Send Command to LCD --------------------//
void cmdLCD(u8 cmd)
{
    IOCLR0 = 1 << RS;     // RS = 0 (Command Register)
    dispLCD(cmd);         // Send command
}

//-------------------- Send Data to LCD --------------------//
void charLCD(u8 data)
{
    IOSET0 = 1 << RS;     // RS = 1 (Data Register)
    dispLCD(data);        // Send character
}

//-------------------- Common LCD Write Function --------------------//
void dispLCD(u8 val)
{
    IOCLR0 = 1 << RW;                 // RW = 0 (Write operation)

    WRITEBYTE(IOPIN0, 8, val);        // Send 8-bit data to LCD

    IOSET0 = 1 << EN;                 // Enable HIGH
    delay_us(1);                      // Small enable pulse

    IOCLR0 = 1 << EN;                 // Enable LOW
    delay_ms(2);                      // Wait for LCD execution
}

//-------------------- Display String --------------------//
void stringLCD(char *ptr)
{
    while(*ptr)                       // Continue until null character
        charLCD(*ptr++);              // Display each character
}

//-------------------- Display Integer --------------------//
void integerLCD(s32 data)
{
    u8 a[30];
    int i = 0, n;

    if(data == 0)
        charLCD('0');                 // Display zero

    if(data < 0)
    {
        data = -data;                 // Convert to positive
        charLCD('-');                 // Display negative sign
    }

    // Extract digits
    while(data)
    {
        a[i++] = (data % 10) + 48;    // Convert digit to ASCII
        data /= 10;
    }

    // Display digits in correct order
    for(n = i - 1; n >= 0; n--)
        charLCD(a[n]);
}

//-------------------- Display Floating Point Number --------------------//
void floatLCD(f32 f)
{
    int num1 = f, num2, n = 0;

    f = f - num1;                     // Extract fractional part

    while(n++ < 6)
        f *= 10;                      // Keep six decimal digits

    num2 = f;

    integerLCD(num1);                 // Display integer part
    charLCD('.');                     // Display decimal point
    integerLCD(num2);                 // Display fractional part
}

//-------------------- Right Indicator Symbol --------------------//
void RIndicatorDisp()
{
    int i;

    // Custom LCD character pattern for right indicator
    char LUT[] = {0x04,0x06,0x1F,0x1F,0x06,0x04,0x00,0x00};

    for(i = 0; i < 8; i++)
    {
        charLCD(LUT[i]);              // Write pattern to CGRAM
    }
}

//-------------------- Left Indicator Symbol --------------------//
void LIndicatorDisp()
{
    int i;

    // Custom LCD character pattern for left indicator
    char LUT[] = {0x04,0x0C,0x1F,0x1F,0x0C,0x04,0x00,0x00};

    for(i = 0; i < 8; i++)
    {
        charLCD(LUT[i]);              // Write pattern to CGRAM
    }
}

//-------------------- Fuel Level - 25% --------------------//
void fuel1()
{
    int i;

    // Custom character representing low fuel level
    char LUT[] = {0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00};

    for(i = 0; i < 8; i++)
    {
        charLCD(LUT[i]);
    }
}

//-------------------- Fuel Level - 50% --------------------//
void fuel2()
{
    int i;

    // Custom character representing half fuel level
    char LUT[] = {0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00};

    for(i = 0; i < 8; i++)
    {
        charLCD(LUT[i]);
    }
}

//-------------------- Fuel Level - 75% --------------------//
void fuel3()
{
    int i;

    // Custom character representing 75% fuel level
    char LUT[] = {0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00};

    for(i = 0; i < 8; i++)
    {
        charLCD(LUT[i]);
    }
}

//-------------------- Fuel Level - 100% --------------------//
void fuel4()
{
    int i;

    // Custom character representing full fuel level
    char LUT[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00};

    for(i = 0; i < 8; i++)
    {
        charLCD(LUT[i]);
    }
}
