#include "Header.h"

double get_values(FILE *infile)
{
	double value = 0;
	fscanf(infile, "%lf", &value);
	return value;
}

double calculate_avg(double sum, double counter)
{
	double avg = 0;
	avg = sum / counter;
	return avg;
}

void print_to_file(FILE *outfile, double avg)
{
	fprintf(outfile, "%lf", avg);
	return 0;
}
