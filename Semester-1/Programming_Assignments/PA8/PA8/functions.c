#include "Header.h"


///////////////////////////////////////Part 1/////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: string_length()
Description: measures the length of a string
Input Parameters: pointer to a string
Returns: string length
*/
int string_length(char *measure)
{
	int length = 0;
	while (*(measure + length) != '\0')
	{
		length++;
	}
	return length;
}

/*
Function: my_str_n_cat()
Description: copies a string onto another string (stopping at null character)
Input Parameters: pointer to destination string, pointer to source string (string to be copied) and length of destination string.
Returns: pointer to destination string 
*/
char my_str_n_cat(char *destination, char *source, int n)	//accepts pointer to a destination character array and a pointer to a source character array
{
	int destination_length = 0;

	destination_length = string_length(destination);	//determines destination string length

	for (int i = 0; i < n; i++)
	{
		*(destination + destination_length + i) = *(source + i);
		if (*(source + i) == '\0')	//If a null character is encountered before n characters have been encountered, copying must stop.
			break;
	}
	
	return destination;	//returns the pointer to the destination character array	
}

/////////////////////////////////////Part 2///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: binary_search()
Description: searches an array of integers for a specified integer
Input Parameters: pointer to array of integers (to be searched), length of array, target value (integer to be searched within the array
Returns: location of integer (or -1 if integer was not found withtin the array)
*/
int binary_search(int *values, int right, int target_value)
{
	int left = 1, found = 0, index = -1, mid = 0;

	while ((found == 0) && (left <= right))
	{
		mid = (right + left) / 2;
		if (target_value == *(values + mid - 1))
		{
			found = 1;
			index = mid;
			break;
		}
		if (target_value < *(values + mid - 1))
			right = mid - 1;
		if (target_value > *(values + mid - 1))
			left = mid + 1;
	}
	return index;
}

/////////////////////////////////////Part 3////////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: str_compare()
Description: bubble sort helper function, compares the asci values of two strings
Input Parameters: pointers to 2 strings
Returns: If left string (string with lower index) is first alphebetically returns integer < 0
		If left comes second, or two strings equal, returns integer >= 0
*/
int str_compare(char *left, char *right)
{
	int compare = 0;
	for (int i = 0; (*(left + i) != '\0') && (*(right) != '\0'); i++)
	{
		if (*(left + i) < *(right + i))	//is left string is smaller (first alphabetically)...
			return -1;
		if (*(left + i) > *(right + i))	//is left string is larger (second alphabetically)...
			return 1;
	}
	return compare;	//if strings are equal, return 0
}

/*
Function: bubble_sort()
Description: Sorts an set of strings alphabetically 
Input Parameters:Accepts an array of pointers to strings and the number of strings as arguments
Returns: N/A
*/
void bubble_sort(char **pointers, int size)
{
	int U = size - 1, C = 1; //set the marker U for the unsorted section at the end of the list (U is an integer index value)
	char *temp = NULL;

	while (U > 0)	//while the unsorted section has more than one element
	{
		C = 1;//set the current element marker C at the second element of the list (C is an integer index value)
		while (C <= U)//while C has not passed U
		{
			if (str_compare(*(pointers + C - 1), *(pointers + C)) > 0)//if the item at position C is less than the item to its left then exchange these two items
			{
				temp = *(pointers + C - 1);
				*(pointers + C - 1) = *(pointers + C);
				*(pointers + C) = temp;
			}
			C += 1;//move C to the right one position	
		}
		U -= 1;//move U left one position	
	}
}

/////////////////////////////////////Part 4//////////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: is_palindrome()
Description: recursively determines if a string is a palindrome
Input Parameters: accepts pointer to a string
Returns: returns 1 for a palindrome, 0 otherwise.
*/
int is_palidrome(char *word, int length)	//accepts a pointer to a string and its length
{
	int palindrome = 0;
	if (word == word + length - 1)	//base case
	{
		palindrome = 1;
		return palindrome;
	}
	if (*word == ' ')//filter white-space on left character (character with lower index)
	{
		palindrome = is_palidrome(word + 1, length - 1);
	}
	else if (*(word + length - 1) == ' ')//filter white-space on right character (character with higherr index)
	{
		palindrome = is_palidrome(word + 1, length - 2);
	}
	else if (*(word) == *(word + length - 1))
	{
		palindrome = is_palidrome(word + 1, length - 2);
	}
	return palindrome;
}

////////////////////////////////////Part 5/////////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: is_prime()
Description: determines is a given number is prime
Input Parameters: integer n
Returns: 0 if integer is not prime, 1 if integer is prime
*/
int is_prime(int n)
{
	int prime = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			prime = 0;
			break;
		}
	}
	return prime;
}

/*
Function: sum_primes()
Description: recursively determines the sum or primes from 2-n (a specified number passed to the function)
Input Parameters: unsigned integer n
Returns: integer sum of all primes from 2 to n
*/
int sum_primes(unsigned int n)	//that accepts an unsigned integer
{
	int sum = 0;
	if (n == 2)
		return 2;
	if (is_prime(n) == 1)
		sum = n + sum_primes(n - 1);
	else
		sum += sum_primes(n - 1);
	return sum;
}

///////////////////////////////////Part 6////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: maximum_occurences()
Description: Determines the frequency of each character found in a string
Input Parameters: accepts a pointer to a string(consisting of alphanumeric and whitespace characters only),
	a pointer to an array of struct occurrences, 
	a pointer to an integer,
	a pointer to a character as arguments.
Returns: pointer to the most frequent letter in the string (letter that occurs the most often)
*/
void maximum_occurences(char *string, Occurrences *occurences, int *max_occurence, char *max_character)
{
	int character = 0, number_of_characters = 0, max_occurences = 0;

	for (int i = 0; *(string + i) != '\0'; i++)	//iterates through the string
	{
		character = *(string + i);
		if (character >= '0' && character <= '9')	//denotes integers 1-10
		{
			character -= '0';
			number_of_characters++;
		}
		else if (character >= 'A' && character <= 'Z')	//capital letters
		{
			character -= ('A' - 10);
			number_of_characters++;
		}
		else if (character >= 'a' && character <= 'z')	//non-capital letters
		{
			character -= ('a' - 36);
			number_of_characters++;
		}
		else continue;

		(occurences + character)->num_occurrences += 1;
	}
	for (int i = 0; i < 61; i++)	//updates frequency for each character
	{
		(occurences + i)->frequency = ((occurences + i)->num_occurrences)/number_of_characters;
	}

	for (int i = 0; i < 61; i++)	//searches for the maximum frequency (with respective character)
	{
		if ((occurences + i)->num_occurrences >= *max_occurence)
		{
			if (i >= 0 && i < 10)
				character = i + '0';
			if (i >= 10 && i < 36)
				character = i + ('A' - 10);
			if (i >= 36 && i < 62)
				character = i + ('a' - 36);

			*max_character = character;
			*max_occurence = (occurences + i)->num_occurrences;
		}
	}
}

//////////////////////////////////Part 7 (Bonus)//////////////////////////////////////////////////////////////////////////////////////////

/*
Function: max_consecutive_integers()
Description: The function finds the maximum consecutive sequence of one integer

Input Parameters: accepts a two - dimensional array of signed integers,
the number of rows and the number of columns.
Returns: two pointers
*/
int max_consecutive_integers(int **int_array, int total_rows, int total_columns, int *address, int *num_integers)
{
	int start_location = 0, count = 1, max_count = 0, *temp_address = int_array;

	for (int row = 0; row < total_rows; row++)
	{
		for (int column = 0; column < total_columns; column++)
		{
			if (row == 4 && column == 4)
				break;
			if (*(int_array + total_columns * row + column) == *(int_array + total_columns * row + column + 1))
			{
				count++;
			}
			else
			{
				if (count > max_count)
				{
					max_count = count;
					*address = temp_address;
					count = 1;
					temp_address = int_array + total_columns * row + column + 1;
				}
				else
				{
					temp_address = int_array + row * total_columns + column + 1;
					count = 1;
				}
			}
		}
	}
	*num_integers = max_count;
}