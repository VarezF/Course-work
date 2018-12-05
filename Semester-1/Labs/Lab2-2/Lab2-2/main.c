
#include "Header.h"

int main()
{
	double theta = 0, distance = 0, velocity = 0, height = 0, time = 0;
	theta = get_theta();
	distance = get_distance();
	velocity = get_velocity();
	time = calc_time(theta, distance, velocity);
	height = calc_height(theta, distance, velocity, time);
	printf_s("Time (sec) of flight: %lf\nTotal height: %lf\n", time, height);
	return 0;
}