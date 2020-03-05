#include <stdio.h>

//compare two integers

int main(void)
{
	int testValue = 0;
	printf("Enter first int: ");
	scanf("%d", &testValue);

	int limitValue = 2;
	printf("Enter second int: ");
	scanf("%d", &limitValue);

	if(testValue >= limitValue ){
		printf("%d is bigger or equal to %d\n", testValue, limitValue);
	}
	else{
		printf("%d is less than %d\n", testValue, limitValue);
	}

	return 0;
}
