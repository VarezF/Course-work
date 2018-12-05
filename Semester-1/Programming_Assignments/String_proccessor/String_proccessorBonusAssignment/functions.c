#include "Header.h"

/*Write a program that performs string processing on all strings.NOTE: You may NOT use the standard library functions found in <string.h>.
Also, you must use only pointer notation and pointer arithmetic, where appropriate!
You may NOT use array notation! Your program should define the following functions:
*/

/*
Function: my_fgets()
Description:Reads at most one less than the number of characters specified by n,
	into the array pointed to by s, from the input pointed to by stream. No more characters are read after a newline is encountered
	or end of file is encountered. The newline if encountered is stored by the array pointed to by s. A null character is appended to the end of string s.
Input Parameters: pointer to character array, integer n (denoting length) and File stream (read).
Returns:If the function is successful in reading characters into s, then s is returned; otherwise a NULL pointer is returned.
*/
char *my_fgets(char *s, int n, FILE *stream)
{
	char *null_ptr = NULL;
	if (!feof(stream))
	{
		for (int i = 0; i < n && !feof(stream); i++)
		{
			fscanf(stream, "%c", s + i);
			if (*(s + i) == '\n')	//if newline is enountered, append null character and end function
			{
				*(s + i + 1) = '\0';	//replaces newline character with null character
				break;
			}
		}
		return s;
	}
	else return null_ptr;
}

/*
Function: my_fputs()
Description: Writes s to the output specified by stream.
Input Parameters: pointer to character array, file stream
Returns: If the function is successful, then it returns the number of characters written to the output; otherwise it returns MY_EOF
	(i.e. for cases where stream does not point any where yet).
*/
int my_fputs(const char *s, FILE *stream)
{
	int length = 0;
	if (stream == NULL)
	{
		return MY_EOF;
	}
	for (int i = 0; *(s + i) != '\0'; i++)
	{
		fprintf(stream,"%c", *(s + i));
		length = i;
	}
	return length;
}

/*
Function:my_fgetc()
Description:Reads the next character from the input pointed to by stream.
Input Parameters:file stream (through which character will be read)
Returns: If the input is at the end of file or a processing error occurs returns MY_EOF; 
	otherwise returns the integer representation of the character read.
*/
int my_fgetc(FILE *stream)
{
	int character = 0;
	if (stream != NULL && !feof(stream))
	{
		fscanf(stream, "%c", &character);
		return character;
	}
	else return MY_EOF;
}

/*
Function:my_putc()
Description: Writes the character c(converted to a character) to the output specified by stream.
Input Parameters: character and file stream (to which the character is used)
Returns:If the write is successful the ascii value of the character is returned; otherwise MY_EOF is returned.
*/
int my_fputc(int c, FILE *stream)
{
	if (stream != NULL)
	{
		fprintf(stream, "%c", &c);
		return c;
	}
	else return MY_EOF;
}

/*
Function:my_gets()
Description: Reads characters from stdin into the array pointed to by s until a newline is encountered.
	The newline character is NOT kept at the end of the array pointed to by s. A null character is written to the end of string s.
Input Parameters: pointer to string 
Returns:The function returns s.
*/
char *my_gets(char *s)
{
	char read = '\0';	//temporary character (allows for newline check before saving in string)
	for (int i = 0;; i++)
	{
		fscanf(stdin, "%c", &read);	//read character and save in temporary read variable
		if (read == '\n')	//checks for newline character before proceeding
		{
			*(s + i) = '\0'; //null character added to end of string
			break;
		}
		else
			*(s + i) = read;	//if newline is not encountered, character is saved into string
	}
	return s;
}

/*
Function:my_puts()
Description: Writes the string pointed to by s to stdout.
	The function appends a newline to the output.
Input Parameters: pointer to string
Returns: number of characters written to the output
*/
int my_puts(const char *s)
{
	int length = 0;
	for (length = 0; *(s + length) != '\0'; length++)
	{
		fprintf(stdout, "%c", *(s + length));
	}
	return length;
}
////////////////////////////////////////////////////Test
/*
Function: my_getchar()
Description: determines the ascii value of the next character read from stdin
Input Parameters: void
Returns: ascii value of character
*/
int my_getchar(void)
{
	int character = 0;
	fscanf(stdin, "%c", &character);
	return character;
}


/*
Function: my_putchar()
Description:The function writes character c to stdout.
Input Parameters:character
Returns:The character c is returned.
*/
int my_putchar(int c)
{
	fprintf(stdout, "%c", c);
	return c;
}

/*
Function: my_strcpy()
Description: Copies all characters in the array pointed to by source into the array
	pointed to by destination. The null character is also copied.
Input Parameters: pointers to source and destination strings
Returns: pointer to destination string
*/
char *my_strcpy(char *destination, const char *source)
{
	for (int i = 0;*(source + i) != '\0'; i++)
	{
		*(destination + i) = *(source + i);	//copies character from source to destination
		if (*(source + i) == '\0')	//breaks after adding null character
			break;
	}
	return destination;
}


/*
Function: my_strncpy()
Description:copies characters from source string into the array pointed to by destination. 
	The function does not copy any characters past a null character. If the string pointed to by source is less than n characters, 
	null characters are appended to the end of the array pointed to by destination until n characters have been written.
Input Parameters: pointers to destination array and source array (characters from source array are added to destination array)
Returns: pointer to destination array
*/
char *my_strncpy(char *destination, const char *source, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(destination + i) = *(source + i);	//copies character from source to destination
		if (*(source + i) == '\0')	//if a null character is encountered before reaching n... 
		{
			for (int j = i; j < n; j++)	//null characters are appended until n is reached
				*(destination + j) = '\0';
			break;
		}
	}
	return destination;
}


/*
Function: my_strcat()
Description: This function appends a copy of the string pointed to by source
	(including the null character) to the end of the string pointed to by destination.
	The append overwrites the null character at the end of destination.
Input Parameters: pointers to destination and source string (both character arrays)
Returns: pointer to destination string (now with source string added)
*/
char *my_strcat(char *destination, const char *source)
{
	for (int i = 0;; i++)
	{
		if (*(destination + i) == '\0')	//begins writing at destinations null character
		{
			for (int n = 0;; n++)
			{
				*(destination + i + n) = *(source + n);
				if (*(source + n) == '\0')	//breaks after null character is copied to destination
					return destination;
			}
		}
	}
	return destination;
}

/*
Function: strncat()
Description: This function appends no more than n characters from the string pointed
	to by source to the end of the array pointed to by destination. The null character is appended to the end of the result.
Input Parameters: pointer to destination string and pointer to source string (source string is added to destination string)
Returns: pointer to destination
*/
char *my_strncat(char *destination, const char *source, int n)
{
	for (int i = 0;; i++)
	{
		if (*(destination + i) == '\0')	//begins writing at destinations null character
		{
			for (int j = 0; j < n; j++)
			{
				*(destination + i + j) = *(source + j);
				if (*(source + j) == '\0')	//breaks after null character is copied to destination
					return destination;
			}
			break;
		}
	}
}

/*
Function: strcmp()
Description:This function compares the string pointed to by s1 to the string pointed to by s2.(the compare function is case sensitive)
Input Parameters: two pointers to the strings being compared
Returns:If the string pointed to by s1 comes before the string pointed to by s2 in dictionary ordering, then - 1 is returned.
	If the string pointed to by s1 is the same as the string pointed to by s2, then 0 is returned.
	Otherwise 1 is returned.
*/
int my_strcmp(const char *s1, const char *s2)
{
	for (int i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
	{
		if (*(s1 + i) < *(s2 + i))
			return -1;
		else if (*(s1 + i) > *(s2 + i))
			return 1;
	}
	return 0;
}


/*
Function: my_strncmp()
Description: Compares no more than n characters(characters following a null character
are not compared) from the string pointed to by s1 to the string pointed to by s2 (the compare function is case sensitive)
Input Parameters: two pointers to the strings being compared
Returns:If the string pointed to by s1 comes before the string pointed to by s2 in dictionary ordering, then - 1 is returned.
	If the string pointed to by s1 is the same as the string pointed to by s2, then 0 is returned.
	Otherwise 1 is returned.
*/
int my_strncmp(const char *s1, const char *s2, int n)
{
	for (int i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n; i++)
	{
		if (*(s1 + i) < *(s2 + i))
			return -1;
		else if (*(s1 + i) > *(s2 + i))
			return 1;
	}
	return 0;
}

/*
Function: my_strlen()
Description: This function returns the length of the string pointed to by s.
	The computation of length does NOT include the null character.
Input Parameters: pointer to character array
Returns: length of string (not including null character)
*/
int my_strlen(const char *s)
{
	int size = 0;
	for (int i = 0; *(s + i) != '\0'; i++)
	{
		size++;
	}
	return size;
}
/*
(10 pts) A main function that tests each of the above implemented functions.You decide how to test your program, making sure to develop good test cases.
You will be graded in part on the quality
*/