// Module: bit operations supporting the handling
// of register manipulation on microcontrollers

//this module's header
#include "bitOperation.h"

// source file

void SetBitNof8( unsigned char* target, unsigned char bitNumber )
{
	*target =(*target | (1 << bitNumber ));
}


void ClearBitNof8( unsigned char* target, unsigned char bitNumber )
{
	*target =(*target &~(1 << bitNumber));
}

void FlipBitNof8( unsigned char* target, unsigned char bitNumber )
{
	*target =(*target ^ (1 << bitNumber));
}

// returns 1 if bit is set, 0 otherwise
unsigned char CheckBitNof8( unsigned char target, unsigned char bitNumber )
{
	// long version
	unsigned char BitIsSet =0;

	if( (target & (1<<bitNumber)) >> bitNumber)
	{ 
		BitIsSet =1;
	}
	else
	{ 
		BitIsSet =0;
	}
	return BitIsSet;
}
