#include"types.h"               // User-defined data type definitions
void Init_LCD(void);             // Initializes the LCD in 8-bit mode.
void dispLCD(u8);                // Displays a single byte on the LCD.
void charLCD(u8);               // Displays a single character at the current cursor position.
void cmdLCD(u8);               // Sends a command to the LCD
void stringLCD(char *);         // Displays a null-terminated string on the LCD.
void integerLCD(s32);           // Displays a signed integer value on the LCD.
void floatLCD(f32);             // Displays a floating-point value on the LCD.
void LIndicatorDisp(void);        // Displays the Left Indicator symbol/animation on the LCD.
void RIndicatorDisp(void);        // Displays the Right Indicator symbol/animation on the LCD.
void fuel1(void);                  // Displays Fuel Level - Stage 1 (Low Fuel).
void fuel2(void);                 // Displays Fuel Level - Stage 2.
void fuel3(void);                  // Displays Fuel Level - Stage 3.
void fuel4(void);                  // Displays Fuel Level - Stage 4 (Full Fuel).

