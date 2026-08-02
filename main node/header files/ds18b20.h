#ifndef _DS18B20_H_        // "if not defined". It is a preprocessor directive in C used to prevent a header file from being included more than once during compilation.
#define _DS18B20_H_         //is a C preprocessor directive used to define macros.

/**DS18B20 FUNCTION DECLARATION**/
unsigned char ResetDS1820(void);      // Sends a reset pulse and checks for the sensor's presence.
unsigned char ReadBit(void);          // Reads a single bit from the DS18B20 using the 1-Wire protocol.
void WriteBit(unsigned char);          // Writes a single bit to the DS18B20 using the 1-Wire protocol.
unsigned char ReadByte(void);           // Reads one byte (8 bits) from the DS18B20.
void WriteByte(unsigned char);           // Writes one byte (8 bits) to the DS18B20.
int ReadTemp(void);                    // Reads the temperature from the DS18B20 sensor

#endif               //"End If". It is a preprocessor directive that marks the end of a conditional compilation block
