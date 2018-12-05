#include <stdio.h>

int main(void)
{
	double bonus = 0;
	char choice = '\0'; 

	printf_s("Enter Y/N for the following:\nAll-star game appearence?\n");
	scanf_s("%c", &choice);
	if (choice == 'Y')
		bonus += 25000;


	printf_s("Regular Season MVP:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y')

		bonus += 75000;

	printf_s("World Series MVP:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y')
		bonus += 100000;

	printf_s("Gold Glove Award:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y')
		bonus += 50000;

	printf_s("Silver Slugger Award:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y')
		bonus += 35000;

	printf_s("Home Run Champ:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y')
		bonus += 25000;

	printf_s("Batting Average Champ:\n");
	scanf_s(" %c", &choice);
	if (choice == 'Y')
		bonus += 25000;

	printf_s("Bonus: %lf\n", bonus);

	return 0;
}