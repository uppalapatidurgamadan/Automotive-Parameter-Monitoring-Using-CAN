#define EINT0_PIN		16              // External Interrupt 0 pin number (P0.16)
#define EINT0_VIC_CHNO	14           // VIC channel number for External Interrupt 0
#define EINT1_PIN		3                 // External Interrupt 1 pin number (P0.3)
#define EINT1_VIC_CHNO	15               // VIC channel number for External Interrupt 1
void Enable_EINTs(void);                // Initializes and enables External Interrupts (EINT0 and EINT1).

