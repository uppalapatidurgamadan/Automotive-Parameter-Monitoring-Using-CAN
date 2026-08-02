//can.h
#include "types.h"             // User-defined data type definitions
typedef struct CAN_Frame       // CAN Frame structure
{	
	u32 ID;                      // CAN Identifier (Standard or Extended ID)
	struct BitField              // Bit-field structure for CAN frame information
	{
		//u32 FF  : 1;
		u32 RTR : 1;             // Remote Transmission Request bit
                                 // 0 = Data Frame
                                 // 1 = Remote Frame
		u32 DLC : 4;             // Data Length Code
                                  // Specifies the number of data bytes (0–8)
	}bfv;	
	u32 Data1,Data2;              // First 4 bytes of CAN data (Byte0–Byte3)
                                   // next 4 bytes of CAN data (Byte0–Byte3)
}CANF;

void Init_CAN1(void);             // Initializes CAN1 controller and configures baud rate,
void CAN1_Tx(CANF txF);           // Transmits a CAN frame through CAN1.
void CAN1_Rx(CANF *rxF);           // Receives a CAN frame from CAN1.
                                   // The received frame is stored in the structure
