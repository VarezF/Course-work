#include "Header.h"

double get_theta()
{
	double theta = 0;
	printf_s("Enter the object angle (radians of elevation:\n");
	scanf_s("%lf", &theta);
	return theta;
}

double get_distance()
{
	double distance = 0;
	printf_s("Enter the objects distance (ft) to target:\n");
	scanf_s("%lf", &distance);
	return distance;
}

double get_velocity()
{
	double velocity = 0;
	printf_s("Enter the objects projectile velocity (ft/s):\n");
	scanf_s("%lf", &velocity);
	return velocity;
}

double calc_time(double theta, double distance, double velocity)
{
	double time = 0;
	time = distance / (velocity * cos(theta));	
	return time;
}
double calc_height(double theta, double distance, double velocity, double time)
{
	double height = 0;
	height = velocity * sin(theta) * time - ((G * pow(time, 2)) / 2);
	return height;
}
