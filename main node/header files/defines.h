#define SETBIT(WORD,BP) WORD|=1<<BP            // Sets (makes 1) the bit at the specified bit position.
#define CLRBIT(WORD,BP) WORD&=~(1<<BP)          // Clears (makes 0) the bit at the specified bit position.
#define CPLBIT(WORD,BP) WORD^=1<<BP                 // Toggles (complements) the bit at the specified bit position.
#define WRITEBIT(WORD,BP,BIT) WORD=((WORD&~(1<<BP))|(BIT<<BP))    // Writes a single bit (0 or 1) at the specified bit position.
#define WRITENIBBLE(WORD,SBP,NIBBLE) WORD=((WORD&~(0xf<<SBP))|(NIBBLE<<SBP))     // Writes a 4-bit nibble at the specified starting bit position.
#define WRITEBYTE(WORD,SBP,BYTE) WORD=((WORD&~(0xff<<SBP))|(BYTE<<SBP))         // Writes an 8-bit byte at the specified starting bit position.
#define WRITEHWORD(WORD,SBP,HWORD) WORD=((WORD&~(0xffff<<SBP))|(HWORD<<SBP))        // Writes a 16-bit half-word at the specified starting bit position.
#define READBIT(WORD,BP) ((WORD>>BP)&1)                 // Reads and returns the value (0 or 1) of the specified bit.

 
