#include "head.h"

double calculate_bmrF(double weight, double height, double age)
{
	double bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	return bmr;
}

double calculate_bmrM(double weight, double height, double age)
{
	double bmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	return bmr;
}

double calculate_bmi(double bmr, double activity)
{
	double bmi = 0;
	if (activity == 1)
		bmi = bmr * 1.2;
	else if (activity == 2)
		bmi = bmr * 1.375;
	else if (activity == 3)
		bmi = bmr * 1.55;
	else if (activity == 4)
		bmi = bmr * 1.725;
	else if (activity == 5)
		bmi = bmr * 1.9;

	return bmi;

}