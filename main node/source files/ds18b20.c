#include <LPC21xx.h>      // LPC21xx register definitions
#include "delay.h"        // Delay function declarations

#define D (1<<17)          // DS18B20 data pin connected to P0.17
#define R (IOPIN0 & (1<<17)) // Read the logic level of the data pin

//-------------------- Reset DS18B20 --------------------//
// Sends a reset pulse and checks for the presence pulse
// Returns:
//   0 -> Sensor detected
//   1 -> Sensor not detected
unsigned char ResetDS18b20(void)
{
    unsigned int presence;

    IODIR0 |= D;          // Configure data pin as output
    IOPIN0 |= D;          // Drive data line HIGH
    delay_us(1);

    IOPIN0 &= ~D;         // Pull data line LOW (Reset pulse)
    delay_us(478);

    IOPIN0 |= D;          // Release data line
    delay_us(54);

    presence = IOPIN0;    // Read presence pulse from sensor

    delay_us(423);

    if(presence & R)
        return 1;         // No device present
    else
        return 0;         // Device detected
}

//-------------------- Read One Bit --------------------//
// Reads a single bit from the DS18B20 using 1-Wire protocol
unsigned char ReadBit(void)
{
    unsigned int B;

    IOPIN0 &= ~D;         // Pull line LOW
    delay_us(1);

    IOPIN0 |= D;          // Release line

    IODIR0 &= ~D;         // Configure pin as input
    delay_us(10);

    B = IOPIN0;           // Read data bit

    IODIR0 |= D;          // Configure pin back as output

    if(B & R)
        return 1;         // Logic HIGH
    else
        return 0;         // Logic LOW
}

//-------------------- Write One Bit --------------------//
// Writes a single bit to the DS18B20
void WriteBit(unsigned char Dbit)
{
    IOPIN0 &= ~D;         // Pull line LOW
    delay_us(1);

    if(Dbit)
        IOPIN0 |= D;      // Release line early to write '1'

    delay_us(58);

    IOPIN0 |= D;          // Release line
    delay_us(1);
}

//-------------------- Read One Byte --------------------//
// Reads 8 bits from DS18B20 (LSB first)
unsigned char ReadByte(void)
{
    unsigned char i;
    unsigned char Din = 0;

    for(i = 0; i < 8; i++)
    {
        Din |= ReadBit() ? (0x01 << i) : Din;
        delay_us(45);
    }

    return Din;
}

//-------------------- Write One Byte --------------------//
// Writes 8 bits to DS18B20 (LSB first)
void WriteByte(unsigned char Dout)
{
    unsigned char i;

    for(i = 0; i < 8; i++)
    {
        WriteBit(Dout & 0x01);    // Send one bit
        Dout >>= 1;               // Shift next bit
        delay_us(1);
    }

    delay_us(98);
}

//-------------------- Read Temperature --------------------//
// Performs temperature conversion and reads the result
// Returns:
//   Temperature value (16-bit raw data)
//   -1 if conversion timeout occurs
int ReadTemp(void)
{
    unsigned char n, buff[2];
    int temp, cnt = 0;

    // Reset sensor and start temperature conversion
    ResetDS18b20();

    WriteByte(0xCC);      // Skip ROM command
    WriteByte(0x44);      // Start temperature conversion

    // Wait until conversion completes
    while(ReadByte() == 0xFF)
    {
        cnt++;

        if(cnt == 12)
        {
            return -1;    // Timeout
        }
    }

    // Reset and read scratchpad memory
    ResetDS18b20();

    WriteByte(0xCC);      // Skip ROM
    WriteByte(0xBE);      // Read Scratchpad command

    // Read first two bytes (Temperature LSB & MSB)
    for(n = 0; n < 2; n++)
    {
        buff[n] = ReadByte();
    }

    // Combine MSB and LSB into a 16-bit temperature value
    temp = buff[1];
    temp <<= 8;
    temp |= buff[0];

    return temp;
}
