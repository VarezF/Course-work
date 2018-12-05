#include "Header.h"

/*
Function: readFile()
Details: Reads from file stream, inputing data into dailyData[] array of FitbitData structs for later use (inputs 0 for empty tokens).
Closes file after use.
Inputs: File stream (created in main), array of structs
Outputs: number of lines that were read from the file stream
*/
int readFile(FILE *infile, FitbitData dailyData[1441])
{

	char line[100] = { '\0' };
	int sumLines = 0;
	fgets(&line, 100, infile);	//gets rid of header info 

	for (sumLines = 0; !feof(infile); sumLines++)	//loops through each line (counting lines each time) until end of file
	{
		fgets(&line, 100, infile);	//reads each record in the file as a string, one line at a time using fgets()

									//////////////////create line tokens/input into struct array (minute,calories,distance,floors,heart,steps,sleep_level)

		char *token = NULL;//break line into substrings to input into struct 

		token = strtok(line, ",");	//TIME	
		strcpy(dailyData[sumLines].minute, token);

		token = strtok(NULL, ",");	//CALORIES 
		if (token != NULL)
		{
			sscanf(token, "%lf", &(dailyData + sumLines)->calories);
		}
		else dailyData[sumLines].calories = 0;

		token = strtok(NULL, ",");	//DISTANCE
		if (token != NULL)
		{
			sscanf(token, "%lf", &(dailyData + sumLines)->distance);
		}
		else dailyData[sumLines].distance = 0;

		token = strtok(NULL, ",");	//FLOORS
		if (token != NULL)
		{
			dailyData[sumLines].floors = atoi(token);
		}
		else dailyData[sumLines].floors = 0;


		token = strtok(NULL, ",");	//HEART RATE
		if (token != NULL)
		{
			dailyData[sumLines].heartRate = atoi(token);
		}
		else dailyData[sumLines].heartRate = 0;

		token = strtok(NULL, ",");	//STEPS
		if (token != NULL)
		{
			dailyData[sumLines].steps = atoi(token);
		}
		else dailyData[sumLines].steps = 0;

		token = strtok(NULL, "\n");	//SLEEP LEVEL
		if (token != NULL)
		{
			dailyData[sumLines].sleepLevel = atoi(token);
		}
		else dailyData[sumLines].sleepLevel = 0;
	}

	fclose(infile);
}

/*
Function: printArray()
Details: prints a specified number of structs from the dailyData struct for testing
Inputs:	array of Fitbit data collected during a 24 hour period
Outputs: N/A
*/
void printArray(FitbitData dailyData[1441])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
		printf("minute:     %s\n", dailyData[i].minute);
		printf("calories:   %lf\n", dailyData[i].calories);
		printf("distance:   %lf\n", dailyData[i].distance);
		printf("floors:     %d\n", dailyData[i].floors);
		printf("heartrate:  %d\n", dailyData[i].heartRate);
		printf("steps:      %d\n\n\n", dailyData[i].steps);
	}
}

/*
Function: totalCalories()
Details: computes the total calories burned throughout a 24 hour period
Inputs: array of Fitbit data collected through a 24 hour period (per min)
Outputs: sum of calories burned
*/
double totalCalories(FitbitData dailyData[1441])
{
	double sumCalories = 0;

	for (int i = 0; i < 1441; i++)
	{
		sumCalories += dailyData[i].calories;
	}
	return sumCalories;
}

/*
Function: distanceWalked()
Details: computes the sum of distances walked (in miles)
Inputs:	array of Fitbit data collected through a 24 hour period (per min)
Outputs: sum of distances walked
*/
double distanceWalked(FitbitData dailyData[1441])
{
	double sumMiles = 0;

	for (int i = 0; i < 1441; i++)
	{
		sumMiles += dailyData[i].distance;
	}
	return sumMiles;
}

/*
Function: floorsWalked()
Details: calculates the total number of floors walked throughout the day
Inputs:	array of Fitbit data collected during a 24 hour period
Outputs: Total number of floors walked
*/
int floorsWalked(FitbitData dailyData[1441])
{
	int sumFloors = 0;

	for (int i = 0; i < 1441; i++)
	{
		sumFloors += dailyData[i].floors;
	}
	return sumFloors;
}

/*
Function: stepsTaken()
Details: Calculates the total number of steps taken
Inputs: array of fitbit data collected during a 24 hour period
Outputs:
*/
int stepsTaken(FitbitData dailyData[1441])
{
	int sumSteps = 0;

	for (int i = 0; i < 1441; i++)
	{
		sumSteps += dailyData[i].steps;
	}
	return sumSteps;
}

/*
Function: avgHeartRate()
Details: Calculates the avg heart rate of an individual during a 24 hour period
Inputs: array of Fitbit data collected during a 24 hour period
Outputs: average heart rate
*/
int avgHeartRate(FitbitData dailyData[1441])
{
	int sumHeartRate = 0, totalSamples = 0, avg = 0;

	for (int i = 0; i < 1441; i++)
	{
		sumHeartRate += dailyData[i].heartRate;
		if (dailyData[i].heartRate != 0)
			totalSamples++;
	}

	avg = sumHeartRate / totalSamples;

	return avg;
}

/*
Function: maxSteps()
Details: calculates the maximum amount of steps during a minute
Inputs: array of Fitbit data collected during a 24 hour period
Outputs: max steps
*/
int maxSteps(FitbitData dailyData[1441])
{
	int max = 0;

	for (int i = 0; i < 1441; i++)
	{
		if (dailyData[i].steps > max)
			max = dailyData[i].steps;
	}
	return max;
}

/*
Function: consecutivePoorSleep()
Details: Searches the Fitbit data for the largest consequtive range of poor sleep (where sleepValue > 1) and reports the start and end time for this range
Inputs: array of Fitbit data collected during a 24 hour period
Outputs: Start and end time for rnage of poorest sleep
*/
char *consecutivePoorSleep(FitbitData dailyData[1441], char range[20])
{
	FitbitData *startPtr = NULL, *maxStartPtr = NULL, *maxEndPtr = 0;
	int sum = 0, maxSum = 0;

	for (int i = 0; i < 1441; i++)
	{
		if (dailyData[i].sleepLevel > 1)
		{
			if (startPtr == NULL)
				startPtr = &dailyData[i];

			sum += dailyData[i].sleepLevel;

			if (sum > maxSum)
			{
				maxSum = sum;
				maxStartPtr = startPtr;
				maxEndPtr = &dailyData[i];
			}
		}
		else
		{
			sum = 0;
			startPtr = NULL;
		}
	}

	strcat(range, (*maxStartPtr).minute);
	strcat(range, "-");
	strcat(range, (*maxEndPtr).minute);

	return range;
}