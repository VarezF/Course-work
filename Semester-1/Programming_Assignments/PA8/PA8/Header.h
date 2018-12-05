#include <stdio.h>
#include <math.h>



///////////////////////////////////////Part 1/////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: string_length()
Description: measures the length of a string
Input Parameters: pointer to a string
Returns: string length
*/
int string_length(char *measure);

/*
Function: my_str_n_cat()
Description: copies a string onto another string (stopping at null character)
Input Parameters: pointer to destination string, pointer to source string (string to be copied) and length of destination string.
Returns: pointer to destination string
*/
char my_str_n_cat(char *destination, char *source, int n);

/////////////////////////////////////Part 2///////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: binary_search()
Description: searches an array of integers for a specified integer
Input Parameters: pointer to array of integers (to be searched), length of array, target value (integer to be searched within the array
Returns: location of integer (or -1 if integer was not found withtin the array)
*/
int binary_search(int *values, int right, int target_value);

/////////////////////////////////////Part 3////////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: str_compare()
Description: bubble sort helper function, compares the asci values of two strings
Input Parameters: pointers to 2 strings
Returns: If left string (string with lower index) is first alphebetically returns integer < 0
If left comes second, or two strings equal, returns integer >= 0
*/
int str_compare(char *left, char *right);

/*
Function: bubble_sort()
Description: Sorts an set of strings alphabetically
Input Parameters:Accepts an array of pointers to strings and the number of strings as arguments
Returns: N/A
*/
void bubble_sort(char **pointers, int size);

/////////////////////////////////////Part 4//////////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: is_palindrome()
Description: recursively determines if a string is a palindrome
Input Parameters: accepts pointer to a string
Returns: returns 1 for a palindrome, 0 otherwise.
*/
int is_palidrome(char *word, int length);

////////////////////////////////////Part 5/////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function: is_prime()
Description: determines is a given number is prime
Input Parameters: integer n
Returns: 0 if integer is not prime, 1 if integer is prime
*/
int is_prime();

/*
Function: sum_primes()
Description: recursively determines the
Input Parameters: unsigned integer n
Returns: integer sum of all primes from 2 to n
*/
int sum_primes(unsigned int n);

////////////////////////////////////Part 6//////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

/*
Function: maximum_occurences()
Description: Determines the frequency of each character found in a string
Input Parameters: accepts a pointer to a string(consisting of alphanumeric and whitespace characters only),
a pointer to an array of struct occurrences, a pointer to an integer, and a pointer to a character as arguments.
Returns: pointer to the most frequent letter in the string (letter that occurs the most often)
*/
void maximum_occurences(char *string, Occurrences *occurences, int *ptrI, char *ptrC);

////////////////////////////////////BONUS Part 7////////////////////////////////////////////////////////////////////////////////////////////

/*
Function: max_consecutive_integers()
Description: The function finds the maximum consecutive sequence of one integer

Input Parameters: accepts a two - dimensional array of signed integers, 
the number of rows and the number of columns.
Returns: two pointers
*/
int max_consecutive_integers(int *int_array, int rows, int columns);
