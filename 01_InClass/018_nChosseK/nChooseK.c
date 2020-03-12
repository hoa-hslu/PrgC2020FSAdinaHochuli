#include <stdio.h>
#include <stdlib.h>

/* compute the factorial of a number */

// prototype
long factorial(int n);
long nChooseK(int n, int k);

int main( int argc, char* argv[] )
{
    int n = 0, k = 0, waitOnValidInput = 1;
	while(waitOnValidInput){
	    printf("Enter two positive integers: ");
    	scanf("%d %d", &n, &k);
		if(n>= 0 && k>= 0 && n>= k) {
		    printf("%d choose %d = %ld\n", n, k, nChooseK(n, k));
			break;
		}
		else
		{
			printf("Invalid input. Try again.\n");
		}
	}
	return EXIT_SUCCESS;
}

//implementation of the nChooseK function
long nChooseK(int n, int k)
{
	long result =0;
		result =factorial(n)/(factorial(k)*factorial(n-k));
	return result;
}

// implementation of the factorial function
long  factorial(int n) {
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}


