#include "head.h"

int main(void)
{
	double weight = 0, height = 0, age = 2, gender = 0, bmr = 0, activity = 0, bmi = 0;

	FILE * infile = NULL;

	infile = fopen("bodydata.txt", "r");
	fscanf(infile, "%lf", &gender);
	fscanf(infile, "%lf", &weight);
	fscanf(infile, "%lf", &height);
	fscanf(infile, "%lf", &age);
	fclose(infile);

	if (gender == 0)
	{
		bmr = calculate_bmrF(weight, height, age);
	}
	else bmr = calculate_bmrM(weight, height, age);

	

	infile = fopen("activitydata.txt", "r");
	fscanf(infile, "%lf", &activity);

	bmi = calculate_bmi(bmr, activity);
	
	printf_s("%lf\n", bmi);

	fclose(infile);

	return 0;

}