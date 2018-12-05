#include <stdio.h>
#include <string.h>

/*******************************************************************************************
* Programmer: Freya Varez																							     *
* Class: CptS 122, Summer 2018; Lab Section 1																			 *
* Programming Assignment: PA1																							 *
* Date: June 11, 2018																									 *
* Description: This program analyzes a file with various Fitbit data, running calculations with this data				 *
*******************************************************************************************/


//type Sleep is enumerated and defined as follows :
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

// C struct to store each of the Fitbit data fields as follows :
typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

/*
Function: readFile()
Details: Reads from file stream, inputing data into dailyData[] array of FitbitData structs for later use (inputs 0 for empty tokens).
Closes file after use.
Inputs: File stream (created in main), array of structs
Outputs: number of lines that were read from the file stream
*/
int readFile(FILE *infile, FitbitData dailyData[1441]);

/*
Function: printArray()
Details: prints a specified number of structs from the dailyData struct for testing
Inputs:	array of Fitbit data collected during a 24 hour period
Outputs: N/A
*/
void printArray(FitbitData dailyData[1441]);	//TESTING FUNCTION

/*
Function: totalCalories()
Details: computes the total calories burned throughout a 24 hour period
Inputs: array of Fitbit data collected through a 24 hour period (per min)
Outputs: sum of calories burned
*/
double totalCalories(FitbitData dailyData[1441]);

/*
Function: distanceWalked()
Details: computes the sum of distances walked (in miles)
Inputs:	array of Fitbit data collected through a 24 hour period (per min)
Outputs: sum of distances walked
*/
double distanceWalked(FitbitData dailyData[1441]);

/*
Function: floorsWalked()
Details: calculates the total number of floors walked throughout the day
Inputs:	array of Fitbit data collected during a 24 hour period
Outputs: Total number of floors walked
*/
int floorsWalked(FitbitData dailyData[1441]);

/*
Function: stepsTaken()
Details: Calculates the total number of steps taken
Inputs: array of fitbit data collected during a 24 hour period
Outputs:
*/
int stepsTaken(FitbitData dailyData[1441]);

/*
Function: avgHeartRate()
Details: Calculates the avg heart rate of an individual during a 24 hour period
Inputs: array of Fitbit data collected during a 24 hour period
Outputs: average heart rate
*/
int avgHeartRate(FitbitData dailyData[1441]);

/*
Function: maxSteps()
Details: calculates the maximum amount of steps during a minute
Inputs: array of Fitbit data collected during a 24 hour period
Outputs: max steps
*/
int maxSteps(FitbitData dailyData[1441]);

/*
Function: consecutivePoorSleep()
Details: Searches the Fitbit data for the largest consequtive range of poor sleep (where sleepValue > 1) and reports the start and end time for this range
Inputs: array of Fitbit data collected during a 24 hour period
Outputs: Start and end time for rnage of poorest sleep
*/
void *consecutivePoorSleep(FitbitData dailyData[1441], char range[20]);

