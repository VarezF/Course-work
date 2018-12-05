/*******************************************************************************************
* Programmer: Freya                                                                     *
* Class: CptS 121, Spring  2018; Lab Section 10                                          *
* Programming Assignment: PA3                                                     *
* Date: February 8, 2018                                                                          *
* Description: functions.c file with various functions corrosponding to the function main.c. Contains the following functions:
			-double read_double(): Reads values from the input file corrosponding to the information of 5 students, assigning them to a floating point variable
			-int read_integer(): Reads values from the input file corrosponding to the information of 5 students, assinging them to an integer variable
			-double calculate_sum(): Calculates the sum of 5 given values 
			-double calculate_mean(): Calculates the mean of 5 given values
			-double calculate_deviation(): Calculates the deviation of a values from its respective mean
			-double calculate_variance(): calculates variance of 5 given values
			-double calculate_standard_deviation(): Calculates standard deviation given a variance from main.c
			-double find_max(): Finds the maximum value in a set of 5 values
			-double find_min(): Finds the minimum value in a set of 5 values
			-void print_double(): prints a given value into an output.c file
*******************************************************************************************/

#include "Header.h"

/*
Description: reads a value from input.dat
inputs: FILE *infile
outputs: double input (value from file as a floating point)
*/
double read_double(FILE *infile)
{
	double input = 0;
	fscanf(infile, "%lf", &input);
	return input;
}


/*
Description: reads a value from input.dat
inputs: FILE *infile
outputs: int input (value from file as an integer value)
*/
int read_integer(FILE *infile)
{
	int input = 0;
	fscanf(infile, "%d", &input);
	return input;
}


/*
Description: calculates the sum of 5 given values
inputs: 5 floating point values 
outputs: the sum of the 5 double values 
*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double sum = 0;
	sum = number1 + number2 + number3 + number4 + number5;
	return sum;
}

/*
Description: calculates the mean given the sum (from the previous function) and total population
inputs: sum of values and population of values
outputs:mean of the set of values
*/
double calculate_mean(double sum, int number)
{
	double mean = 0;
	mean = sum / number;
	return mean;
}

/*
Description: calculates the deviation of a value from main.c by finding its deviation
	from the mean (in previous function). 
inputs: mean of a set and value from that set
outputs: deviation of the value from it's respective mean
*/
double calculate_deviation(double number, double mean)
{
	double deviation = 0;
	deviation = number - mean;
	return deviation;
}


/*
Description: calculates the the total variance of 5 values
inputs: a set of 5 values from main.c as well as the sets population
outputs: variance of the set
*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double variance = 0;
	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number;
	return variance;
}

/*
Description: calculates the standard deviation of a set given its variance (from previous function)
inputs: variance of the set 
outputs: deviation of the set
*/
double calculate_standard_deviation(double variance)
{
	double deviation = 0;
	deviation = sqrt(variance);
	return deviation;
}


/*
Description: finds the maximum value of a set of 5 values by comparing them to the rest of the values in the set
inputs: a set of 5 values
outputs: the maximum value of the set
*/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max = number1;
	
	if (max < number2)
		max = number2;
	if (max < number3)
		max = number3;
	if (max < number4)
		max = number4;
	if (max < number5)
		max = number5;

	return max;
}

/*
Description: finds the minimum value of a set of 5 values
inputs: set of 5 values
outputs: minimum of the set
*/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min = number1;

	if (min > number2)
		min = number2;
	if (min > number3)
		min = number3;
	if (min > number4)
		min = number4;
	if (min > number5)
		min = number5;

	return min;
}

/*
Description: prints a value to an output.dat file
inputs: double value
outputs: void
*/
void print_double(FILE *outfile, double number)
{
	fprintf(outfile, "%lf", number);
	return 0;
}
