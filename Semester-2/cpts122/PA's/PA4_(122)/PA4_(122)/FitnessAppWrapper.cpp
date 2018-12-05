#include "FitnessAppWrapper.h"

/////CONSTRUCTORS//////////////
FitnessAppWrapper::FitnessAppWrapper()
{
	mdietStream.open("dietPlans.txt");	//initializes fstreams to corrosponding file
	mexerciseStream.open("exercisePlans.txt");
}

DietList::DietList()
{
	for (int i = 0; i < 7; i++)
	{
		DietNode *pMem = new DietNode;
		addToEnd(pMem, &mpHead, &mpTail);
	}
}

ExerciseList::ExerciseList()
{
	for (int i = 0; i < 7; i++)
	{
		ExerciseNode *pMem = new ExerciseNode;
		addToEnd(pMem, &mpHead, &mpTail);
	}
}

///////GETTERS///////////////////

DietNode* DietList::getDietpHead()
{
	return mpHead;
}

DietNode* DietList::getDietpTail()
{
	return mpTail;
}

ExerciseNode* ExerciseList::getExpHead()
{
	return mpHead;
}

ExerciseNode* ExerciseList::getExpTail()
{
	return mpTail;
}

/////OTHER////////////////////
/*function: runApp()
Description: simulates the main appliation
Input: N/A
Output:N/A
*/
void FitnessAppWrapper::runApp()	//starts the main application.
{
	int userChoice = 0;
	while (1)
	{
		userChoice = displayMenu();

		if (userChoice == 1)
		{
			loadWeeklyDietPlan(mdietStream, mDietList);
			mdietStream.close();
		}
		else if (userChoice == 2)
		{
			loadWeeklyExPlan(mexerciseStream, mExerciseList);
			mexerciseStream.close();
		}
		else if (userChoice == 3)
			storeWeeklyDietPlan(mDietList);
		else if (userChoice == 4)
			storeWeeklyExPlan(mExerciseList);
		else if (userChoice == 5)
			displayWeeklyDietPlan(mDietList);
		else if (userChoice == 6)
			displayWeeklyExPlan(mExerciseList);
		else if (userChoice == 7)
			editDietPlan(mDietList);
		else if (userChoice == 8)
			editExercisePlan(mExerciseList);
		else
			break;	//if user chooses to exit
	}
	storeWeeklyDietPlan(mDietList);;	//Stores current data into filestream (precondition: User chooses to exit)
	storeWeeklyExPlan(mExerciseList);
}	

/*function:
Description: Prints out fitness application menu, prompts user for an option
Input: N/A
Output: Integer 1-9 denoting users choice (to be completed in runApp()
*/
int FitnessAppWrapper::displayMenu()
{
	int userChoice = 0;
	while (1)
	{
		std::cout << "____________________Fitness Application______________________" << std::endl
			<< "1.    Load weekly diet plan from file." << std::endl
			<< "2.    Load weekly exercise plan from file." << std::endl
			<< "3.    Store weekly diet plan to file." << std::endl
			<< "4.    Store weekly exercise plan to file." << std::endl
			<< "5.    Display weekly diet plan to screen." << std::endl
			<< "6.    Display weekly exercise plan to screen." << std::endl
			<< "7.    Edit daily diet plan." << std::endl
			<< "8.    Edit daily exercise plan." << std::endl
			<< "9.    Save and exit." << std::endl;
		std::cin >> userChoice;
		system("cls");
		if (userChoice > 0 && userChoice < 10)
			break;
		else std::cout << "Error: Please enter an option 1-9" << std::endl;
	}
	return userChoice;
}

/*function: addToEnd()
Description: assists List class in adding new ListNodes (Note: overloaded for DietPlan and ExercisePlan data)
	Assists Load...() functions in saving information read from file into List
Input: new data to be added to LinkNode
Output: N/A
*/
void DietList::addToEnd(DietNode *pMem, DietNode **pHead, DietNode **pTail)
{
	if (*pHead == NULL)	//if linked list is currently empty
	{
		*pHead = pMem;
		*pTail = *pHead;	//set pHead = pTail (as only one node exists)
	}
	else {
		(*pTail)->setpNext(pMem);
		pMem->setpPrev(*pTail);
		*pTail = pMem;
	}
}

/*function: addToEnd()
Description: assists List class in adding new ListNodes (Note: overloaded for DietPlan and ExercisePlan data)
	Assists Load...() functions in saving information read from file into List
Input: new data to be added to LinkNode
Output: N/A
*/
void ExerciseList::addToEnd(ExerciseNode *pMem, ExerciseNode **pHead, ExerciseNode **pTail)
{
	if (*pHead == NULL)	//if linked list is currently empty
	{
		*pHead = pMem;
		*pTail = *pHead;	//set pHead = pTail (as only one node exists)
	}
	else {
		(*pTail)->setpNext(pMem);
		pMem->setpPrev(*pTail);
		*pTail = pMem;
	}
}

/*function: loadDailyDietPlan()
Description: reads one record from the given stream (Precondition: file is already open), creates new node for data in List
Input: filestream from which data will be read
Output: N/A (data is stored into the List class)
*/
void FitnessAppWrapper::loadDailyDietPlan(std::fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

/*function: loadDailyExPlan()
Description: reads one record from the given stream (Precondition: file is already open)
Input: file stream, address of plan to be filled
Output:*/
void FitnessAppWrapper::loadDailyExPlan(std::fstream &fileStream, ExercisePlan &plan)
{
	fileStream >> plan;
}

/*function:loadWeeklyDietPlan()
Description: reads in all seven daily plans from the given stream (precondition: file is already open)
Input: filestream being read, 7-node list to be filled with data from file
Output:*/
void FitnessAppWrapper::loadWeeklyDietPlan(std::fstream &fileStream, DietList &list)//reads in all seven daily plans from the given stream.
{
	DietNode *pCur = list.getDietpHead();	
	while (pCur != NULL)
	{
		loadDailyDietPlan(fileStream, *(pCur->getPlan()));
		pCur = pCur->getpNext();
	}
	std::cout << "Successfully loaded" << std::endl;
	system("pause");
	system("cls");
}

/*function:loadWeeklyDietPlan()
Description: reads in all seven daily plans from the given stream (precondition: file is already open)
Input: filestream being read, 7-node list to be filled with data from file
Output:*/
void FitnessAppWrapper::loadWeeklyExPlan(std::fstream &fileStream, ExerciseList &list)
{
	ExerciseNode *pCur = list.getExpHead();
	while (pCur != NULL)
	{
		loadDailyExPlan(fileStream, *pCur->getPlan());
		pCur = pCur->getpNext();
	}
	std::cout << "Successfully loaded" << std::endl;
	system("pause");
	system("cls");
}

/*function: displayDailyDietPlan()
Description: displays current plan for the day
Input: pointer to node containing day for which data will be printed
Output: N/A
*/
void FitnessAppWrapper::displayDailyDietPlan(DietPlan &plan)	//writes daily plan to screen
{
	std::cout << plan;
}

/*function: displayDailyExPlan()
Description: displays current plan for the day
Input: pointer to node containing day for which data will be printed
Output: N/A
*/
void FitnessAppWrapper::displayDailyExPlan(ExercisePlan &plan)	//writes daily plan to screen
{
	std::cout << plan;
}

/*function: displayWeeklyDietPlan()
Description: displays 7-day plan list 
Input: pointer to list containing days for which data will be printed
Output: N/A
*/
void FitnessAppWrapper::displayWeeklyDietPlan(DietList list)	//writes a weekly plan to the screen. calls displayDailyPlan().
{
	DietNode *pCur = list.getDietpHead();
	while (pCur != NULL)
	{
		displayDailyDietPlan(*pCur->getPlan());
		pCur = pCur->getpNext();
	}
	system("pause");
	system("cls");
}

/*function: displayWeeklyDietPlan()
Description: displays 7-day plan list
Input: pointer to list containing days for which data will be printed
Output: N/A
*/
void FitnessAppWrapper::displayWeeklyExPlan(ExerciseList list)
{
	ExerciseNode *pCur = list.getExpHead();
	while (pCur != NULL)
	{
		displayDailyExPlan(*pCur->getPlan());
		pCur = pCur->getpNext();
	}
	system("pause");
	system("cls");
}

/*function: storeDailyDietPlan()
Description: stores current data from linked list into file for later use
Input: filestream, plan to be transfered to filestream
Output: N/A
*/
void FitnessAppWrapper::storeDailyDietPlan(std::fstream &fileStream, DietPlan &plan)	//writes a daily plan to a file
{
	fileStream << plan;
}

/*function: storeDailyExPlan()
Description: stores current data from linked list into file for later use
Input: filestream, plan to be transfered to filestream
Output: N/A
*/
void FitnessAppWrapper::storeDailyExPlan(std::fstream &fileStream, ExercisePlan &plan)
{
	fileStream << plan;
}

/*function: storeWeeklyDietPlan()
Description: stores current data from linked list into file for later use
Input: plans to be transfered to filestream
Output: N/A
*/
void FitnessAppWrapper::storeWeeklyDietPlan(DietList list)
{
	std::fstream fileStream;
	fileStream.open("dietPlans.txt", std::fstream::out | std::fstream::trunc);
	DietNode *pCur = list.getDietpHead();
	while (pCur != NULL)
	{
		storeDailyDietPlan(fileStream, *pCur->getPlan());
		pCur = pCur->getpNext();
	}
	fileStream.close();
}

/*function: storeWeeklyExPlan()
Description: stores current data from linked list into file for later use
Input: plans to be transfered to filestream
Output: N/A
*/
void FitnessAppWrapper::storeWeeklyExPlan(ExerciseList list)
{
	std::fstream fileStream;
	fileStream.open("exercisePlans.txt", std::fstream::out | std::fstream::trunc);
	ExerciseNode *pCur = list.getExpHead();
	while (pCur != NULL)
	{
		storeDailyExPlan(fileStream, *pCur->getPlan());
		pCur = pCur->getpNext();
	}
	fileStream.close();
}

/*function: editDietPlan()
Description: iterates through the linked list, prompting user for changes to the data of each node
Input: List holding data
Output: N/A
*/
void FitnessAppWrapper::editDietPlan(DietList list)
{
	DietNode *pCur = list.getDietpHead();
	std::string name, date, temp;
	int userChoice = 0, calories = 0;
	while (pCur != NULL)
	{
		std::cout << "________________________Editing Dieting Plan_____________________" << std::endl;
		displayDailyDietPlan(*pCur->getPlan());
		std::cout << "1.) Edit plan name" << std::endl
			<< "2.) Edit caloric goal" << std::endl
			<< "3.) Edit date" << std::endl
			<< "4.) Go to next day" << std::endl
			<< "5.) Exit edit menu" << std::endl;

		std::cin >> userChoice;
		system("cls");
		if (userChoice == 1)	//edit name
		{
			std::cout << "Enter a new name: ";
			std::getline(std::cin, temp);	//No idea why I have to call getline() twice for this one... but hey, it works
			std::getline(std::cin, name);
			pCur->getPlan()->setplanName(name);
			std::cout << "successfully edited" << std::endl;
			_sleep(1000);
			system("cls");
		}
		else if (userChoice == 2)	//edit steps goal
		{
			std::cout << "Choose caloric goal: ";
			std::cin >> calories;
			pCur->getPlan()->setGoalCalories(calories);
			std::cout << "successfully edited" << std::endl;
			_sleep(1000);
			system("cls");
		}
		else if (userChoice == 3)	//edit date
		{
			std::cout << "Choose a new date: ";
			std::getline(std::cin, temp);
			std::getline(std::cin, date);
			pCur->getPlan()->setDate(date);
			std::cout << "successfully edited" << std::endl;
			_sleep(1000);
			system("cls");
		}
		else if (userChoice == 5)	//exit
			break;
		else if (userChoice < 0 || userChoice > 5)
			std::cout << "Error: Please choose one of the following options" << std::endl;
		pCur = pCur->getpNext();
	}
	system("pause");
	system("cls");
}

/*function: editDExercisePlan()
Description: iterates through the linked list, prompting user for changes to the data of each node
Input: List holding data
Output: N/A
*/
void FitnessAppWrapper::editExercisePlan(ExerciseList list)
{
	ExerciseNode *pCur = list.getExpHead();
	std::string name, date, temp;
	int userChoice = 0, steps = 0;
	while (pCur != NULL)
	{
		std::cout << "________________________Editing Exercise Plan_____________________" << std::endl;
		displayDailyExPlan(*pCur->getPlan());
		std::cout << "1.) Edit plan name" << std::endl
			<< "2.) Edit steps goal" << std::endl
			<< "3.) Edit date" << std::endl
			<< "4.) Go to next day" << std::endl
			<< "5.) Exit edit menu" << std::endl;

		std::cin >> userChoice;
		system("cls");
		if (userChoice == 1)	//edit name
		{
			std::cout << "Enter a new name: ";
			std::getline(std::cin, temp);	//No idea why I have to call getline() twice for this one... but hey, it works
			std::getline(std::cin, name);
			pCur->getPlan()->setplanName(name);
			std::cout << "successfully edited" << std::endl;
			_sleep(1000);
			system("cls");
		}
		else if (userChoice == 2)	//edit steps goal
		{
			std::cout << "Choose steps goal: ";
			std::cin >> steps;
			pCur->getPlan()->setGoalSteps(steps);
			std::cout << "successfully edited" << std::endl;
			_sleep(1000);
			system("cls");
		}
		else if (userChoice == 3)	//edit date
		{
			std::cout << "Choose a new date: ";
			std::getline(std::cin, temp);	
			std::getline(std::cin, date);
			pCur->getPlan()->setDate(date);
			std::cout << "successfully edited" << std::endl;
			_sleep(1000);
			system("cls");
		}
		else if (userChoice == 5)	//exit
			break;
		else if (userChoice < 0 || userChoice > 5)
			std::cout << "Error: Please choose one of the following options" << std::endl;
		pCur = pCur->getpNext();
	}
	system("pause");
	system("cls");
}

///////////////////////OVERLOADED OPERATORS///////////
std::fstream & operator >> (std::fstream &lhs, DietPlan &rhs)
{
	std::string name;
	std::getline(lhs, name);
	rhs.setplanName(name);

	int goal = 0;
	lhs >> goal;
	rhs.setGoalCalories(goal);

	std::string temp;
	std::getline(lhs, temp);	//reads and discards empty line

	std::string date;
	std::getline(lhs, date);
	rhs.setDate(date);

	std::getline(lhs, temp);	//reads and discards empty line

	return lhs;
}

std::fstream & operator >> (std::fstream &lhs, ExercisePlan &rhs)
{
	std::string name;
	std::getline(lhs, name);
	rhs.setplanName(name);

	int goal = 0;
	lhs >> goal;
	rhs.setGoalSteps(goal);

	std::string temp;
	std::getline(lhs, temp);	//reads and discards empty line

	std::string date;
	std::getline(lhs, date);
	rhs.setDate(date);

	std::getline(lhs, temp);	//reads and discards empty line

	return lhs;
}

std::fstream & operator << (std::fstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getPlanName() << std::endl
		<< rhs.getGoalSteps() << std::endl
		<< rhs.getDate() << std::endl << std::endl;	//(adds extra newline at end)

	return lhs;
}

std::fstream & operator << (std::fstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getPlanName() << std::endl 
		<< rhs.getGoalCalories() << std::endl
		<< rhs.getDate() << std::endl << std::endl;	//(adds extra newline at end)

	return lhs;
}

std::ostream & operator << (std::ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getPlanName() << std::endl
		<< rhs.getGoalCalories() << std::endl
		<< rhs.getDate() << std::endl << std::endl;	//(adds extra newline at end)

	return lhs;
}

std::ostream & operator << (std::ostream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getPlanName() << std::endl
		<< rhs.getGoalSteps() << std::endl
		<< rhs.getDate() << std::endl << std::endl;	//(adds extra newline at end)

	return lhs;
}