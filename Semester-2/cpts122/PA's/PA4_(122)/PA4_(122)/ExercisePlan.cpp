#include "ExercisePlan.h"

/////CONSTRUCTORS///
ExercisePlan::ExercisePlan(int goalSteps, string planName, string date)
{
	mGoalSteps = goalSteps;
	mPlanName = planName;
	mDate = date;
}

ExercisePlan::ExercisePlan(ExercisePlan &copyPlan)
{
	mGoalSteps = copyPlan.mGoalSteps;
	mPlanName = copyPlan.mPlanName;
	mDate = copyPlan.mDate;
}

ExerciseNode::ExerciseNode(ExerciseNode *pNext, ExerciseNode *pPrev)
{
	mpNext = pNext;
	mpPrev = pPrev;
	mpExercisePlan = new ExercisePlan;
}

////DESTRUCTORS////////
ExercisePlan::~ExercisePlan()
{
	std::cout << "Successfully deconstructed" << std::endl;
	system("pause");
	system("cls");
}

ExerciseNode::~ExerciseNode()
{
	std::cout << "Successfully deconstructed" << std::endl;
	system("pause");
	system("cls");
}

/////SETTERS/////////
void ExercisePlan::setGoalSteps(int newGoalSteps)
{
	mGoalSteps = newGoalSteps;
}

void ExercisePlan::setplanName(string newPlanName)
{
	mPlanName = newPlanName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

void ExerciseNode::setpNext(ExerciseNode *p)
{
	mpNext = p;
}

void ExerciseNode::setpPrev(ExerciseNode *p)
{
	mpPrev = p;
}

/////GETTERS/////////
int ExercisePlan::getGoalSteps()
{
	return mGoalSteps;
}

string ExercisePlan::getPlanName()
{
	return mPlanName;
}

string ExercisePlan::getDate()
{
	return mDate;
}

ExerciseNode* ExerciseNode::getpNext()
{
	return mpNext;
}

ExerciseNode* ExerciseNode::getpPrev()
{
	return mpPrev;
}

ExercisePlan* ExerciseNode::getPlan()
{
	return mpExercisePlan;
}

////OTHER///////////
void ExercisePlan::editGoal()
{
	std::cout << "Enter new goal:" << std::endl;
	std::cin >> mGoalSteps;
	system("cls");
	std::cout << "Successfully edited" << std::endl;
	system("pause");
	system("cls");
}