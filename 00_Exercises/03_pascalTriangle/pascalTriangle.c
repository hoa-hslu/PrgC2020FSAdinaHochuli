#include <stdio.h>
#include <stdlib.h>

void PrintUsageMessage(void);
void PrintPascalTriangle( int triangleLimit );

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
			PrintPascalTriangle( inputValue );
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
	printf("Usage: pascalTriangle wholeNumber\n\twholeNumber: integer on the interval [%d,%d]\n", lowerLimit, upperLimit);
}

void PrintPascalTriangle( int triangleLimit )
{
	int coef=1, space;
	for(int i = 0; i < triangleLimit; i++ )
	{
		for(space=1; space <= triangleLimit-i; space++)
			printf("     ");
		for(int j = 0; j <= i; j++ )
		{
			if (j==0 || i==0)
				coef=1;
			else
				coef=coef*(i-j+1)/j;			
			printf("%10d", coef);
		}
		printf("\n");
	}

}





