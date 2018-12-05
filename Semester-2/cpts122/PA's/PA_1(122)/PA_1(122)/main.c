#include "Header.h"

int main()
{
	FitbitData dailyData[1441] = { { NULL } };	//array of FitbitData that can store 24 hours of minute data (array of size 1440)

	FILE *infile = NULL;

	infile = fopen("FitbitData.csv", "r");
	if (infile == NULL)
	{
		printf("Error: could not read file\n");
		system("pause");
		return 0;
	}
	else
	{
		int sumLines = 0;
		sumLines = readFile(infile, dailyData);	// reads “FitbitData.csv”, inputing data into struct array
	}

	//compute the total calories burned, distance walked in miles, floors walked, steps taken, avg heart rate, max steps and range of poor sleep/////////
	int sumFloors = 0, sumSteps = 0, avgHeart = 0, max_Steps = 0;
	double sumCalories = 0, sumDistance = 0;
	char poorSleepRange[20] = { '\0' };

	sumCalories = totalCalories(dailyData);
	sumDistance = distanceWalked(dailyData);
	sumFloors = floorsWalked(dailyData);
	sumSteps = stepsTaken(dailyData);
	avgHeart = avgHeartRate(dailyData);
	max_Steps = maxSteps(dailyData);
	consecutivePoorSleep(dailyData, poorSleepRange);

	/*open “Results.csv” for mode write. Output two lines to “Results.csv” and to the screen in the following format:
o   Line 1 : Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep
o   Line 2 : valueCalories, valueDistance, valueFloors, valueSteps, valueHeartrate, valueMax, valueSleepStart : valueSleepEnd
	*/

	FILE *outfile = NULL;
	outfile = fopen("results.csv", "w");

	fprintf(outfile,"Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	fprintf(outfile,"%lf, %lf, %d, %d, %d, %d, %s\n", sumCalories, sumDistance, sumFloors, sumSteps, avgHeart, max_Steps, poorSleepRange);

	printf("Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	printf("%lf, %lf, %d, %d, %d, %d, %s\n", sumCalories, sumDistance, sumFloors, sumSteps, avgHeart, max_Steps, poorSleepRange);

	fclose(outfile);	//Note, infile is closed within readFile()

	return 0;
}