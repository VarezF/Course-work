#include "Header.h"

int calculate_sum(FILE *infile)
{
	int sum = 0;
	while (!feof(infile))
	{
		int integer = 0;
		fscanf(infile, "%d", &integer);
		sum += integer;
	}
	return sum;
}

int determine_prime(int sum)
{
	int prime = 1;
	for (int i = 2; i <= sqrt(sum) && prime == 1; i++)
	{
		if (sum%i == 0)
			prime = 0;
	}
	return prime;
}

int digit_sum(int sum)
{
	int remainder = 0, digitSum = 0;

	for (int i = 10; sum%i - remainder != 0; i = i * 10)
	{
		digitSum += sum%i - remainder;
		sum = sum / i;
		remainder = sum%i;
	}
	return sum;
}

int calculate_individual_prime(int sum)
{
	int prime = 1;

	for (int i = 2; i <= sqrt(sum) && prime == 1; i++)
	{
		if (sum%i == 0)
			prime = 0;
	}
	return prime;
}

