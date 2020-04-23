#include <stdio.h>
#include <stdlib.h>

void printBinary( unsigned int input );

int main( int argc, char *argv[] )
{

	unsigned int a =12, b =25;
	
	// AND
	printf("*** AND ***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a&b);

	// OR
	printf("\n*** OR ***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a|b);

	// XOR
	printf("\n*** XOR ***\n");
	printBinary(a);
	printBinary(b);
	printBinary(a^b);

	// Complement
	printf("\n*** complement ***\n");
	printBinary(a);
	printBinary(-a);

	// shift left
	printf("\n*** shift left ***\n");
	printBinary(a);
	printBinary(a << 1);

	// shift right
	printf("\n*** shift right ***\n");
	printBinary(a);
	printBinary(a >> 1);

	// bit masking: Set bit 5 --> OR!!
	unsigned char c		=0b00001100;
	unsigned char mask	=0b00100000; // set bit 5
	printf("\n*** set bit 5 ***\n");
	printBinary(c);
	unsigned char d =c | mask;
	printBinary(d);
	mask =1;	// 0n00000001
	printBinary(c | mask << 5 ); //WICHTIG, MERKEN!
	// c = c | mask << 5; // register verändern

	// bit masking: Clear bit 5 --> AND!!
	mask =0b11011111; // clear bit 5
	printf("\n*** clear bit 5 ***\n");
	printBinary(d);
	printBinary(d & mask);
	printBinary(d &~(mask << 5) ); //WICHTIG, MERKEN!

	// Check if bit 3 is set
	printf("\n*** check bit 3 ***\n");
	printBinary(d);
	mask =0b00001000;
	printBinary( d & mask);
	printBinary( d & (1 << 3));

	// flip bits 3 and 0 
	printf("\n*** flip bit 3 and 0 ***\n");
	printBinary(d);
	mask =0b00001001;
	printBinary( d ^ mask);
	printBinary( d ^ ((1 << 3) | 1));
	//					bit3	bit0


return EXIT_SUCCESS;
}



void printBinary( unsigned int input )
{
	unsigned int i =0;

	printf("%u =\t 0b", input);

	for( i = (1 << 31 ); i > 0; i = (i>>1) )
	{
		if( input & i)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");

}
