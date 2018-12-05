#include "Header.h"

int main(void)
{
	//1. Write a program which populates an array with integer values read from a file.
	FILE *infile = NULL;
	int array[100] = { 0 }, size = 0;

	infile = fopen("input.txt", "r");

	size = populate_array(array, infile);

	printf("size = %d\n", size);

	for (int i = 0; i <= size; i++)
	{
		printf("%d\n", array[i]);
	}

	printf("-------------------\n");

	reverse_array(array, size);

	for (int i = 0; i <= size; i++)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}