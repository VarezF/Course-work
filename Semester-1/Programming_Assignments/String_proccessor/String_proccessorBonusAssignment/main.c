#include "Header.h"

int main(void)	//File errors?
{
	/////////////////////////my_fgets()////////////////////////////////////////////////////////////////////*
	FILE *infile = NULL;
	char string[100] = { '\0' };

	infile = fopen("test.txt", "r");

	for (int i = 0; i < 8; i++)
	{
		my_fgets(string, 50, infile);
		printf(string);
	}

	///////////////////////my_fputs()////////////////////////////////////////////////////////////////////*

	my_fputs("But first, enter your favorite string below:\n", stdout);

	/////////////////////my_gets()/////////////////////////////////////////////////////////////////////////*

	my_gets(string);

	system("cls");

	printf("You went with \"%s\"?\n\n", string);

	//////////////////////my_puts()///////////////////////////////////////////////////////////////////////*

	my_puts("Interesting choice...\n");

	/////////////////////my_getchar()/////////////////////////////////////////////////////////////////////*

	printf("If you say so, now choose a letter:");

	char user_character = '\0';

	user_character = my_getchar();

	system("cls");

	/////////////////////my_putchar()//////////////////////////////////////////////////////////////////////*

	printf("Good choice! %c is my favorite character too!\n\n", my_putchar(user_character));

	/////////////////////my_strcpy()//////////////////////////////////////////////////////////////////////*

	char string2[100] = "Ah, your string! It's taking ov-";
	my_strcpy(string2, string);

	////////////////////mystrncpy()/////////////////////////////////////////////////////////////////////*

	char destination[30] = "Destination", source[30] = "source";
	my_strncpy(destination, source, 5);

	////////////////////my_strcat()/////////////////////////////////////////////////////////////////////*

	char test_string[100] = "Nooo! Your string! it's taking ov-";

	my_strcat(test_string, string);

	printf(test_string);

	////////////////////my_strncat()//////////////////////////////////////////////////////////////////////*

	my_strncat(string2, "Beep boop", 7);

	////////////////////my_strcmp()////////////////////////////////////////////////////////////////////////
	char compare1[] = "My string", compare2[] = "Your string!";

	if (my_strcmp(compare1, compare2) < 0)
		printf("%s < %s\n", compare1, compare2);
	else if (my_strcmp(compare1, compare2) == 0)
		printf("%s = %s\n", compare1, compare2);
	else printf("%s > %s\n", compare1, compare2);

	////////////////////my_strncmp()///////////////////////////////////////////////////////////////////////

	if (my_strncmp(compare1, compare2, 6) < 0)
		printf("%s < %s\n", compare1, compare2);
	else if (my_strncmp(compare1, compare2, 6) == 0)
		printf("%s = %s\n", compare1, compare2);
	else printf("%s > %s\n", compare1, compare2);
	////////////////////my_strlen()//////////////////////////////////////////////////////////////////////

	my_strlen(string);

	//////////////////////Close Files/////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 100; i++)
	{
		printf("%s", string);
	}

	fclose(infile);

	return 0;
}