#include "Header.h"

int main(void)
{
	FILE *infile = NULL;
	int sum = 0, prime = 0, digitSum = 0;

	infile = fopen("input.txt", "r");

	sum = calculate_sum(infile);

	printf("sum = %d\n", sum);

	digitSum = digit_sum(sum);

	printf("Sum of digits = %d", digitSum);	

	calculate_individual_prime(infile, digitSum);

	printf("primativity of sum: True = 1, false = 0:\n%d\n", prime);

	fclose(infile);

	return 0;
}