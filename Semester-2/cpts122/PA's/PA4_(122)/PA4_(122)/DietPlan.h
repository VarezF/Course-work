#pragma once
#include <iostream>
//4.    1 pt – declaring and defining a destructor

using std::string;

class DietPlan {
public:
	DietPlan(int goalCalories = 0, std::string planName = { '\0' }, std::string date = { '\0' });	//constructors
	DietPlan(DietPlan &copyDietPlan);	//copy constructor

	~DietPlan();	//destructor

	void setGoalCalories(int newGoalCalories);	//setters	
	void setplanName(std::string newPlanName);
	void setDate(std::string newDate);

	int getGoalCalories();	//getters
	std::string getPlanName();
	std::string getDate();

	void editGoal();

private:
	int mGoalCalories;
	std::string mPlanName;
	std::string mDate;
};

class DietNode {	//ListNode for DietPlan List
public:
	DietNode(DietNode *pNext = NULL, DietNode *pPrev = NULL);	//constructors

	~DietNode();	//destructor

	void setpNext(DietNode *p);	//setters
	void setpPrev(DietNode *p);

	DietNode *getpNext();	//getters
	DietNode *getpPrev();
	DietPlan *getPlan();

private:
	DietNode *mpNext;
	DietNode *mpPrev;
	DietPlan *mpDietPlan;
};