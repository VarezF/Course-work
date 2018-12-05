/*Freya Varez*/

# include <stdio.h>
# include <math.h>


double get_height()
{
	double height = 0;
	printf_s("Enter height in feet:\n");
	scanf_s("%lf", &height);
	return height;
}

double get_weight()
{
	double weight = 0;
	printf_s("Enter weight in pounds:\n");
	scanf_s("%lf", &weight);
	return weight;
}

double convert_height_to_inches(double height)
{
	height = height * 12;
	return height;
}

double calculate_bmi(double weight, double height)
{
	double bmi = 0;
	height = convert_height_to_inches(height);
	bmi = (weight / pow(height, 2)) * 703;
	return bmi;
}
void display_bmi(double bmi)
{
	printf("BMI: %lf\n", bmi);
}
int main(void)
{
	double height = 0, weight = 0, bmi = 0;
	height = get_height();
	weight = get_weight();
	bmi = calculate_bmi(weight, height);
	display_bmi(bmi);
	return 0;
}