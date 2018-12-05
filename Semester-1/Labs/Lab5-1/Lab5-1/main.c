#include "Header.h"

int main(void)
{
	FILE *infile = NULL;
	FILE *outfile = NULL;

	infile = fopen("input.txt", "r");
	outfile = fopen("output.txt", "w");
	
	double max = 0, min = 0;
	max = get_values(infile);
	min = max;

	for (int i = 0; !feof(infile); i++)
	{
		double num = 0;
		num = get_values(infile);
		if (num > max)
			max = num;
		if (num < max)
			min = num;
	}
	printf("max = %lf\nMin = %lf\n", max, min);

	fclose(infile);
	fclose(outfile);
	/* Close your files. */

	return 0;
}