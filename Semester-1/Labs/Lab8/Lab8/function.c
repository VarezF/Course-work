#include "Header.h"

int populate_array(int array[], FILE *infile)
{
	int size = 0;
	for (size; fscanf(infile, "%d", &array[size]) != EOF; size++)
	{ }
	return size;
}

int reverse_array(int array[], int size)
{
	int temp = 0;
	for (int i = 0; i < (size / 2); i++)
	{
		temp = array[i];
		array[i] = array[size - i];
		array[size - i] = temp;
	}
	return 0;
}