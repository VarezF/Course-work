#include "Header.h"

int main(void)
{
	//To grader: The following commented sections are for testing each of the functions 
	//(please test only one at a time, as variables for each function may have the same name)


	/*//////////////////////////////////////////////////////////////////////////////////////////////////////////Part 1
	char destination[20] = "Hello ";
	char source[20] = "Freya!";

	my_str_n_cat(&destination, &source, 10);

	for (int i = 0; i < 20; i++)
	{
		printf("%c", destination[i]);
		if (destination[i] == '\0')
			break;
	}
	*/

	////////////////////////////////////////////////////////////////////////////////////////////////////////Part 2
	int values[] = { 1, 2, 3, 3, 4, 5 };

	int found = binary_search(&values, 6, 3);

	if (found > 0)
		printf("Target found at %d\n", found);
	else
		printf("Target not found\n");


	/*///////////////////////////////////////////////////////////////////////////////////////////////////////Part 3
	char one[] = "Zebra", two[] = "Wax", three[] = "Bye", four[] = "Apple";
	int size = 4;

	char *pointers[4] = {&one, &two, &three, &four};

	/////////////Print current list//////////
	printf("Original list:\n");
	for (int string = 0; string < 4; string++)
	{
		for (int character = 0; character < 10; character++)
		{
			printf("%c", *(*(pointers + string) + character));
			if (*(*(pointers + string) + character) == '\0')
				break;
		}
		printf("\n");
	}
	printf("\n\n");

	bubble_sort(&pointers, size);

	//////////Print sorted list///////////////////
	printf("Sorted list:\n");
	for (int string = 0; string < 4; string++)
	{
		for (int character = 0; character < 10; character++)
		{
			printf("%c", *(*(pointers + string) + character));
			if (*(*(pointers + string) + character) == '\0')
				break;
		}
		printf("\n");
	}
	*/

	/*/////////////////////////////////////////////////////////////////////////////////////////////////Part 4
	char word[] = "r har";
	int length = 5;

	int palindrome = is_palidrome(&word, length);

	if (palindrome == 1)
		printf("Is a palindrome\n");
	else
	*/

	/*//////////////////////////////////////////////////////////////////////////////////////////////////////Part 5
	unsigned int n = 10;

	int sum = 0;

	sum = sum_primes(n);

	printf("n = %d\nprime sum = %d\n", n, sum);
	*/

	/*//////////////////////////////////////////////////////////////////////////////////////////////////////////Part 6
	char string[] = "aaa BB XYZ";
	Occurrences occurences[61] = { {0} };

	int max_occurence = 0;
	char max_character = '\0';

	maximum_occurences(string, occurences, &max_occurence, &max_character);

	printf("Letter with maximum occurence: %c\nNumber of occurences: %d\n", max_character, max_occurence);
	*/

	/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////Part 7 (Bonus)
	int int_array[3][2] = { { 0 } }, total_rows = 3, total_columns = 2, address = 0, num_integers = 0;

	printf("   0 1 2 3 4 \n");	//print array
	for (int row = 0; row < total_rows; row++)
	{
		printf("%d ", row);
		for (int column = 0; column < total_columns; column++)
		{
			int_array[row][column] = rand() % 3;
			printf(" %d", int_array[row][column]);
		}
		printf("\n");
	}

	max_consecutive_integers(int_array, total_rows, total_columns, &address, &num_integers);

	printf("Address: %d\nNumber of Consecutive integers: %d\n", address, num_integers);
	*/

}