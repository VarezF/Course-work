#include "DietPlan.h"

/////CONSTRUCTORS///
DietPlan::DietPlan(int goalCalories, std::string planName, std::string date)
{
	mGoalCalories = goalCalories;
	mPlanName = planName;
	mDate = date;
}

DietNode::DietNode(DietNode *pNext, DietNode *pPrev)
{
	mpNext = pNext;
	mpPrev = pPrev;
	mpDietPlan = new DietPlan;
}

DietPlan::DietPlan(DietPlan &copyDietPlan)
{
	mGoalCalories = copyDietPlan.mGoalCalories;
	mPlanName = copyDietPlan.mPlanName;
	mDate = copyDietPlan.mDate;
}

/////DESTRUCTOR//////////
DietPlan::~DietPlan()
{
	std::cout << "Successfully deconstructed" << std::endl;
	system("pause");
	system("cls");
}

DietNode::~DietNode()
{
	std::cout << "Successfully deconstructed" << std::endl;
	system("pause");
	system("cls");
}

/////SETTERS///////////////
void DietPlan::setGoalCalories(int newGoalCalories)
{
	mGoalCalories = newGoalCalories;
}   

void DietPlan::setplanName(std::string newPlanName)
{
	mPlanName = newPlanName;
}

void DietPlan::setDate(std::string newDate)
{
	mDate = newDate;
}

void DietNode::setpNext(DietNode *p)
{
	mpNext = p;
}

void DietNode::setpPrev(DietNode *p)
{
	mpPrev = p;
}

/////GETTERS/////////
int DietPlan::getGoalCalories()
{
	return mGoalCalories;
}

string DietPlan::getPlanName()
{
	return mPlanName;
}

string DietPlan::getDate()
{
	return mDate;
}

DietNode* DietNode::getpNext()
{
	return mpNext;
}

DietNode* DietNode::getpPrev()
{
	return mpPrev;
}

DietPlan* DietNode::getPlan()
{
	return mpDietPlan;
}

////OTHER/////////////
void DietPlan::editGoal()
{
	std::cout << "Enter new goal:" << std::endl;
	std::cin >> mGoalCalories;
	system("cls");
	std::cout << "Successfully edited" << std::endl;
	system("pause");
	system("cls");
}