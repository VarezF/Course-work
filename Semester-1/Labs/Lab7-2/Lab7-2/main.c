#include "Header.h"

int main(void)
{
	double revenue_total = 0, revenue_prediction = 0, time = 0;
	int year = 0;

	printf("Enter time (in years) since 1985:\n");
	scanf("%lf", &time);
	printf("Enter revenue prediction");
	scanf("%lf", &revenue_prediction);

	revenue_total = calculate_revenue(time);

	year = predict(revenue_prediction);

	printf("revenue = %lf\nPrediction year = %d", revenue_total, year);

	return 0;
}