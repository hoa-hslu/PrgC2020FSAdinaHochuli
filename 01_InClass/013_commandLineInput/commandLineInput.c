#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	printf("Number of input arguments: %d\n", argc);

	for(int i = 1; i< argc; i++)
	{
		int x = atoi(argv[i]);
		printf("Argument %d was %s and as an int %d\n", i, argv[i], x);
	}

	return 0;
}
