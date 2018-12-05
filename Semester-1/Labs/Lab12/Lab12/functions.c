#include "Header.h"
void print_bits(int num)
{
	int bit[32] = { 0 };
	for (int i = 0; i < 32 || num != 0; i++)
	{
		if (num % 2 == 0)
		{
			bit[31 - i] = 0;
			num /= 2;
		}
		else
		{
			bit[31 - i] = 1;
			num -= 1;
			num /= 2;
		}
	}
	for (int i = 0; i < 32; i++)
	{
		printf("%d", bit[i]);
	}
	printf("\n\n");
}

void shift_4(int num)
{
	num = num >> 4;
	print_bits(num);
}

void pow_2(int num, int pow)
{
	print_bits(num);
	num = num << pow;
	printf("%d\n", num);
	print_bits(num);
}

void pack_characters(char one, char two, char three, char four)
{
	printf("%c%c%c%c\n\n", one, two, three, four);
	
	unsigned int var1 = one, var2 = two, var3 = three, var4 = four, var = 0;
	print_bits(var1);
	print_bits(var2);
	print_bits(var3);
	print_bits(var4);

	var = var1;
	var = var << 8;
	var = var | var2;
	var = var << 8;
	var = var | var3;
	var = var << 8;
	var = var | var4;

	print_bits(var);
}