#include "Header.h"

double calculate_revenue(double time)
{
	double revenue = 0;
	revenue = 203 * pow(1.071, time);
	return revenue;

}

int predict(double revenue)
{
	int year = 0;
	year = log(revenue / 203.265)/log(1.071) + 1984;
	return year;
}