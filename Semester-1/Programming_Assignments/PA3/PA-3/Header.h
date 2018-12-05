/*******************************************************************************************
* Programmer: Freya                                                                     *
* Class: CptS 121, Spring  2018; Lab Section 10                                          *
* Programming Assignment: PA3                                                     *
* Date: February 8, 2018                                                                          *
* Description: header.c file contains function prototypes for the following functions used within main.c:
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

#include <stdio.h>
#include <math.h>

double read_double(FILE *infile);//Reads values from the input file corrosponding to the information of 5 students, assigning them to a floating point variable

int read_integer(FILE *infile); //Reads values from the input file corrosponding to the information of 5 students, assinging them to an integer variable

double calculate_sum(double number1, double number2, double number3, double number4, double number5);//Calculates the sum of 5 given values

double calculate_mean(double sum, int number);//Calculates the mean of 5 given values (using their sum from main.c

double calculate_deviation(double number, double mean);//Calculates the deviation of a values from its respective mean
 
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);//calculates variance of 5 given values

double calculate_standard_deviation(double variance);//Calculates standard deviation given a variance from main.c

double find_max(double number1, double number2, double number3, double number4, double number5);//Finds the maximum value in a set of 5 values

double find_min(double number1, double number2, double number3, double number4, double number5);//Finds the minimum value in a set of 5 values

void print_double(FILE *outfile, double number);//prints a given value into an output.c file