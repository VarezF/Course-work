#pragma once
#include <iostream>

using std::string;

class ExercisePlan {
public:
	ExercisePlan(int goalSteps = 0, string planName = { '\0' }, string date = { '\0' });	//constructors
	ExercisePlan(ExercisePlan &copyPlan);	//copy constructor

	~ExercisePlan();	//destructor

	void setGoalSteps(int newGoalSteps);	//setters
	void setplanName(string newPlanName);
	void setDate(string newDate);

	int getGoalSteps();	//getters
	string getPlanName();
	string getDate();

	void editGoal();

private:
	int mGoalSteps;
	string mPlanName;
	string mDate;
};

class ExerciseNode {	//ListNode for DietPlan List
public:
	ExerciseNode(ExerciseNode *pNext = NULL, ExerciseNode *pPrev = NULL);	//constructors

	~ExerciseNode();	//destructor

	void setpNext(ExerciseNode *p);	//setters
	void setpPrev(ExerciseNode *p);

	ExerciseNode *getpNext();	//getters
	ExerciseNode *getpPrev();
	ExercisePlan *getPlan();

private:
	ExerciseNode *mpNext;
	ExerciseNode *mpPrev;
	ExercisePlan *mpExercisePlan;
};