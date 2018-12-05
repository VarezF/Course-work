/*******************************************************************************************
* Programmer: Freya                                                                     *
* Class: CptS 121, Spring  2018; Lab Section 10                                          *
* Programming Assignment: PA3                                                     *
* Date: February 8, 2018                                                                          *
* Description: This program takes various floating point and integer values from a file input.dat 
        corrosponding to 5 peoples student information:
*			-Student ID
*			-GPA
*			-Class standing
*			-Age
		Then calculates GPA Mean, Class Standing Mean, Age Mean, GPA Standard Deviation, GPA Min and GPA Max, 
		outputting these values into a file output.dat.
*******************************************************************************************/

#include "Header.h"

int main(void)
{
	int student_id1 = 0, student_id2 = 0, student_id3 = 0, student_id4 = 0, student_id5 = 0,
		class_standing1 = 0, class_standing2 = 0, class_standing3 = 0, class_standing4 = 0, class_standing5 = 0;

	double gpa1 = 0, gpa2 = 0, gpa3 = 0, gpa4 = 0, gpa5 = 0, gpaSum = 0,
		age1 = 0, age2 = 0, age3 = 0, age4 = 0, age5 = 0, ageSum = 0,
		class_standingSum = 0;

	FILE * infile = NULL, *outfile = NULL;

	infile = fopen("input.dat", "r");//Opens an input file "input.dat" for reading; 
									 /*Expected Input File Format (real numbers only):
									 -Student ID# (an 8 digit integer number)
									 -GPA (a floating-point value to the hundredths place)
									 -Class Standing (1 - 4, where 1 is a freshmen, 2 is a sophomore, 3 is a junior, and 4 is a senior --> all integers)
									 -Age (a floating-point value)*/
	outfile = fopen("output.dat", "w");//Opens an output file "output.dat" for writing; 

	//Reads five records from the input file (input.dat)
	student_id1 = read_integer(infile);             //reading first record
	gpa1 = read_double(infile);					    //
	class_standing1 = read_integer(infile);         //
	age1 = read_double(infile);                     //

	student_id2 = read_integer(infile);             //reading second record
	gpa2 = read_double(infile);						//
	class_standing2 = read_integer(infile);			//
	age2 = read_double(infile);						//

	student_id3 = read_integer(infile);				//reading third record
	gpa3 = read_double(infile);						//
	class_standing3 = read_integer(infile);			//
	age3 = read_double(infile);						//

	student_id4 = read_integer(infile);				//reading fourth record
	gpa4 = read_double(infile);						//
	class_standing4 = read_integer(infile);			//
	age4 = read_double(infile);						//

	student_id5 = read_integer(infile);				//reading fifth record
	gpa5 = read_double(infile);						//
	class_standing5 = read_integer(infile);			//
	age5 = read_double(infile);						//


	gpaSum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5); //Calculates the sum of the GPAs
	class_standingSum = calculate_sum(class_standing1, class_standing2, class_standing3, class_standing4, class_standing5);//Calculates the sum of the class standings;
	ageSum = calculate_sum(age1, age2, age3, age4, age5);//Calculates the sum of the ages

	double gpaMean = 0, class_standingMean = 0, ageMean = 0;//create variables for Mean calcuations

	gpaMean = calculate_mean(gpaSum, 5);//Calculates the mean of the GPAs, writing the result to the output file (output.dat)
	print_double(outfile, gpaMean);//prints mean of GPA to output file

	class_standingMean = calculate_mean(class_standingSum, 5);//Calculates the mean of the class standings, writing the result to the output file (output.dat);
	print_double(outfile, class_standingMean);//prints class_standingMean to output file

	ageMean = calculate_mean(ageSum, 5);//Calculates the mean of the ages, writing the result to the output file (output.dat)
	print_double(outfile, ageMean);//prints ageMean to output file

	double gpa1dev = 0, gpa2dev = 0, gpa3dev = 0, gpa4dev = 0, gpa5dev = 0;//creates variables to calculate deviation of each gpa from the mean

	//Calculate the deviation of each GPA from the mean
	gpa1dev = calculate_deviation(gpaMean, gpa1);
	gpa2dev = calculate_deviation(gpaMean, gpa2);
	gpa3dev = calculate_deviation(gpaMean, gpa3);
	gpa3dev = calculate_deviation(gpaMean, gpa4);
	gpa4dev = calculate_deviation(gpaMean, gpa5);

	double variance = 0;//create variable for variance calculations
	variance = calculate_variance(gpa1dev, gpa2dev, gpa3dev, gpa4dev, gpa5dev, 5);//Calculate the variance of the GPAs

	double stdev = 0; //create variable for standard veiation calculations
	stdev = calculate_standard_deviation(variance);//Calculates the standard deviation of the GPAs, writing the result to the output file (output.dat);
	print_double(outfile, stdev);

	double min = 0, max = 0;// creates variables for min and max calculations
	
	min = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);//Determines the min of the GPAs, writing the result to the output file (output.dat)
	print_double(outfile, min);

	max = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);//Determines the max of the GPAs, writing the result to the output file (output.dat)
	print_double(outfile, max);

	fclose(infile);//Closes the input file
	fclose(outfile);//closes output file

	return 0;
}
