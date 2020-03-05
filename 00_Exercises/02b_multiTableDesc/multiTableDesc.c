#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void);
void PrintMultiTable( int tableLimit );

const int lowerLimit = 1;
const int upperLimit = 20;

int main( int argc, char* argv[] )
{
	int inputValue = 0;
	if( argc != 2 )	{
		PrintUsageMessage();
		return 0;
	}
	else
	{
		inputValue = atoi(argv[1]);
		if (inputValue >= lowerLimit && inputValue <= upperLimit)
		{
			// input is valid
			PrintMultiTable( inputValue );
		}
		else
		{
			// no valid input
			PrintUsageMessage();
			return 0;
		}
	}
	return 0;
}

void PrintUsageMessage(void)
{
	printf("Usage: multiTable wholeNumber\n\twholeNumber: integer on the interval [lowerLimit,upperLimit]\n");
}

void PrintMultiTable( int tableLimit )
{
	for(int i = tableLimit; i >=1 ; i-- )
	{
		for(int j = tableLimit; j >= 1; j-- )
		{
			printf("%d\t", i*j);
		}
		printf("\n");
	}

}







