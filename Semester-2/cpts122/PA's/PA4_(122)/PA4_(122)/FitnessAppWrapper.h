#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"
#include <fstream>
#include <string>

class DietList {	////////////linked list with diet plans
public:
	DietList();
	void addToEnd(DietNode *pMem, DietNode **pHead, DietNode **pTail);

	DietNode *getDietpHead();
	DietNode *getDietpTail();

private:
	DietNode *mpHead = NULL;
	DietNode *mpTail = NULL;
};

class ExerciseList {	////////linked list with exercise plans
public:
	ExerciseList();
	void addToEnd(ExerciseNode *pMem, ExerciseNode **pHead, ExerciseNode **pTail);

	ExerciseNode *getExpHead();
	ExerciseNode *getExpTail();

private:
	ExerciseNode *mpHead = NULL;
	ExerciseNode *mpTail = NULL;
};

///////////////////////////////////////////////////////////WRAPPER/////////////////////////////////////////////////////////////////////
class FitnessAppWrapper {
public:
	FitnessAppWrapper();

	void runApp();	//starts the main application.
	void loadDailyDietPlan(std::fstream &fileStream, DietPlan &plan);	//reads one record from the given stream.
	void loadDailyExPlan(std::fstream &fileStream, ExercisePlan &plan);	//reads one record from the given stream.

	void loadWeeklyDietPlan(std::fstream &fileStream, DietList &List);//reads in all seven daily plans from the given stream.
	void loadWeeklyExPlan(std::fstream &fileStream, ExerciseList &List);

	void displayDailyDietPlan(DietPlan &plan);	//writes daily plan to screen
	void displayDailyExPlan(ExercisePlan &plan);

	void displayWeeklyDietPlan(DietList list);	//writes a weekly plan to the screen. calls displayDailyPlan().
	void displayWeeklyExPlan(ExerciseList list);

	void storeDailyDietPlan(std::fstream &fileStream, DietPlan &plan);	//writes a daily plan to a file
	void storeDailyExPlan(std::fstream &fileStream, ExercisePlan &plan);

	void storeWeeklyDietPlan(DietList list);
	void storeWeeklyExPlan(ExerciseList list);

	void editExercisePlan(ExerciseList mExerciseList);
	void editDietPlan(DietList mDietList);

	int displayMenu();

private:
	DietList mDietList;
	ExerciseList mExerciseList;
	std::fstream mdietStream, mexerciseStream;
};

////////STREAM EXTRACTION////
std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs);

std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs);

/////STREAM INSERTION////////
std::fstream & operator << (std::fstream &lhs, DietPlan &rhs);

std::fstream & operator << (std::fstream &lhs, ExercisePlan &rhs);

std::ostream & operator << (std::ostream &lhs, DietPlan &rhs);

std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs);