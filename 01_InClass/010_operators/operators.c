#include <stdio.h>

int main(void)
{
	//ex1
	short largeShort = 32760;
	largeShort = largeShort + 12345;

	printf("%d\n", largeShort);

	//ex2
	int numerator = 19, denominator = 5, result = 0, rest = 0;
	result = numerator/denominator;
	rest =numerator%denominator;

	printf("result: %d\n rest: %d\n", result, rest);

	//ex3
	float e = 2.718281828f;
	e++;
	printf("%f\n", e);
	e--;
	printf("%f\n", e);

	//ex4 --> funktioniert nicht!!
	//double dblNumerator = 12.8;
	//dblNumerator = dblNumerator%3;

	//printf("%f\n", dblNumerator);

	return 0;
}
