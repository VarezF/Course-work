#include "AppWrapper.h"
#include <windows.h>
#include <ctime>

appWrapper::appWrapper()	//constructor
{
	//nothing to initialize (?)
}

appWrapper::~appWrapper()	//destructor
{
	//std::cout << "appWrapper destructor called" << std::endl;	//DELETE AFTER TESTING
}

List appWrapper::getlist()	//getters
{
	return mList;
}

void appWrapper::displayMenu()
{
	while (1)
	{
		int userChoice = 0;
		while (1)
		{
		std::cout << "___________________Menu___________________________" << std::endl
			<< "1.    Import course list" << std::endl
			<< "2.    Load master list" << std::endl
			<< "3.    Store master list" << std::endl
			<< "4.    Mark absences" << std::endl
			<< "5.    Edit absences" << std::endl
			<< "6.    Generate report" << std::endl
			<< "7.    Exit" << std::endl;

			std::cin >> userChoice;
			system("cls");
			if (userChoice > 0 && userChoice < 8)
				break;
			else std::cout << "Error: Please enter one the following choices" << std::endl;
		}
			if (userChoice == 1)	//import course list
		{
			import();
			std::cout << "Successfully imported" << std::endl;
			Sleep(1000);	//splash screen notifying user of successfull import
			system("cls");
		}
		else if (userChoice == 2)	//load master list
		{
			load();
			std::cout << "Successfully loaded" << std::endl;
			Sleep(1000);	//splash screen notifying user of successfull load
			system("cls");
		}
		else if (userChoice == 3)	//store master list
		{
			store();
			std::cout << "Successfully stored" << std::endl;
			Sleep(1000);	//splash screen notifying user of successfull storage
			system("cls");
		}
		else if (userChoice == 4)	//mark absences
		{
			markAbsences();
			std::cout << "Absences recorded" << std::endl;
			Sleep(1000);	//splash screen notifying user of success
			system("cls");
		}
		else if (userChoice == 5)	//edit absences
		{
			editAbsences();
		}
		else if (userChoice == 6)	//generate report
		{
			generateReport();
		}
		else break;	//exit
	}
	store();
}

/*
function: import()
details: Reads the.csv course file and overwrites the master list.
input: N/A
output: N/A
*/
void appWrapper::import()
{
	if (mList.getpHead() != nullptr)	//deletes old list (if one exists)
		deleteList(mList.getpHead());
	std::fstream infile;	//create and open filestream to csv file
	infile.open("classList.csv");
	mList.setpHead(new ListNode);
	ListNode *pCur = mList.getpHead(), *pTemp;
	std::string temp;
	getline(infile, temp);	//reads and discards header line
	while (!infile.eof())
	{
		std::getline(infile, temp, ',');	//discard
		if (temp == "\0")
			break;	//if on empty line break 

		std::getline(infile, temp, ',');	//ID
		pCur->setmID(temp);

		std::getline(infile, temp, '"');	//read and discard quotation
		std::getline(infile, temp, '"');	//Name
		pCur->setmName(temp);
		std::getline(infile, temp, ',');	//grab remaining and discard

		std::getline(infile, temp, ',');	//Email
		pCur->setmEmail(temp);

		std::getline(infile, temp, ',');	//Units
		pCur->setUnits(temp);

		std::getline(infile, temp, ',');	//Program
		pCur->setmProgram(temp);

		std::getline(infile, temp);	//level
		pCur->setmLevel(temp);

		pCur->setpNext(new ListNode);
		pTemp = pCur;	//keeps track of previous node (in case where file is empty and pNext is deleted/set to null)
		pCur = pCur->getpNext();
	}
	delete(pCur);	//delete last node (pCur) currently empty
	pTemp->setpNext(nullptr);
	infile.close();
}

/*
function: load()
details: Populates the master list with previous nodes from master.txt.
input: N/A
output: N/A
*/
void appWrapper::load()
{
	if(mList.getpHead() != nullptr)
		deleteList(mList.getpHead());	//delete existing list (if one exist) 
	std::fstream infile;
	infile.open("master.txt");	//file containing previous nodes
	std::string temp;
	int totalAbsences = 0;
	ListNode *pCur = new ListNode, *pTemp;	//begin new list, with newly allocated mpHead
	mList.setpHead(pCur);

	while (!infile.eof())
	{
		std::getline(infile, temp);
		if (temp == "\0")
			break;
		pCur->setmID(temp);

		std::getline(infile, temp);
		pCur->setmName(temp);

		std::getline(infile, temp);
		pCur->setmEmail(temp);

		std::getline(infile, temp);
		pCur->setUnits(temp);

		std::getline(infile, temp);
		pCur->setmProgram(temp);

		std::getline(infile, temp);
		pCur->setmLevel(temp);

		std::getline(infile, temp);
		pCur->getStack()->setmSize(std::stoi(temp));

		if (pCur->getStack()->getmSize() > 0)	//if absences are to follow in file 
		{
			for (totalAbsences = 0;; totalAbsences++)	//gather remaining lines (before empty line) as dates of absence
			{
				getline(infile, temp);
				if (temp == "\0")	//if empty line is encountered, break (and move to next students data)
					break;
				else {
					if (totalAbsences >= pCur->getStack()->getmCapacity()) //arrived at arrays max capacity, allocate additional memory
					{
						std::string *temp = new std::string[pCur->getStack()->getmCapacity() * 2];	//allocate new memory
						temp = pCur->getStack()->getpTop(); //copy from old array
						pCur->getStack()->setpTop(temp);
					}
					*(pCur->getStack()->getpTop() + totalAbsences) = temp;
				}
			}
		}
		else
			std::getline(infile, temp);	//advance past empty line (discarded)
		pCur->getStack()->setmSize(totalAbsences);
		pTemp = pCur;
		pCur->setpNext(new ListNode);
		pCur = pCur->getpNext();
	}
	delete(pCur);
	pTemp->setpNext(nullptr);
	infile.close();
}

/*
function: store()
details: Stores the contents of the master list’s nodes to master.txt.
input: N/A
output: N/A
*/
void appWrapper::store()	
{
	std::fstream outfile;
	outfile.open("master.txt");
	ListNode *pCur = mList.getpHead();
	for (int i = 0; pCur != NULL; i++)
	{
		outfile << pCur->getmID() << std::endl
			<< pCur->getmName() << std::endl
			<< pCur->getmEmail() << std::endl
			<< pCur->getUnits() << std::endl
			<< pCur->getmProgram() << std::endl
			<< pCur->getmLevel() << std::endl
			<< pCur->getStack()->getmSize() << std::endl;
		for (int i = 0; i < pCur->getStack()->getmSize(); i++)	//iterates through stack to copy dates of absence
		{
			outfile << *(pCur->getStack()->getpTop() + i) << std::endl;
		}
		outfile << std::endl;	//paste empty line to differentiate between students records
		pCur = pCur->getpNext();
	}
	outfile.close();	//close filestream
}

/*
function: markAbsences()
details: Runs through the master list, displays each student’s name, and prompts if he / she was absent for the current day.
		The data must be pushed to the stack that is contained within the node representative of the student.
input: N/A
output: N/A
*/
void appWrapper::markAbsences()
{
	ListNode *pCur = mList.getpHead();
	char userChoice = '\0';
	std::string time;
	int size = 0;
	while (pCur != NULL)
	{
		while (1)
		{
			std::cout << "Was " << pCur->getmName() << " absent today (Y/N)?" << std::endl;
			std::cin >> userChoice;
			system("cls");
			if (userChoice == 'Y' || userChoice == 'y')
			{
				if (pCur->getStack()->getmSize() + 1 >= pCur->getStack()->getmCapacity())	//if capacity is reached, allocate new memory
				{
					std::string *temp = new std::string[pCur->getStack()->getmCapacity() * 2];	//allocate new memory
					temp = pCur->getStack()->getpTop(); //copy from old array
					pCur->getStack()->setpTop(temp);
				}						
				std::time_t t = std::time(0);  // Get current time 
				std::tm* now = std::localtime(&t);	//(retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
				time += std::to_string(now->tm_year + 1900) + '-' + 
					std::to_string(now->tm_mon + 1) + '-' + std::to_string(now->tm_mday);

				*(pCur->getStack()->getpTop() + pCur->getStack()->getmSize()) = time;

				size = pCur->getStack()->getmSize();
				pCur->getStack()->setmSize(size + 1);
				time = { "\0" }; //re-initialize time to empty string
				size = 0;
				break;
			}
			else if (userChoice == 'N' || userChoice == 'n')
				break;
			else std::cout << "Error: Please enter Y/N" << std::endl;
		}
		pCur = pCur->getpNext();
	}
}

/*
function: editAbsences()
details: Prompts for an ID number or name of student to edit and date of absence to edit.
input: N/A
output: N/A
*/
void appWrapper::editAbsences()
{
	std::string search, newDate;
	std::cout << "__________Edit Absences__________" << std::endl
		<< "Enter a name or ID to search:   ";
	std::getline(std::cin, search);
	std::getline(std::cin, search);
	system("cls");
	char userChoice = '\0';
	ListNode *pCur = mList.getpHead();
	while (pCur != nullptr)
	{
		if (search == pCur->getmName() || search == pCur->getmID())
		{
			std::cout << pCur->getmID() << std::endl
				<< pCur->getmName() << std::endl
				<< pCur->getmEmail() << std::endl
				<< pCur->getUnits() << std::endl
				<< pCur->getmLevel() << std::endl << std::endl;
			if (pCur->getStack()->getmSize() == 0)
			{
				std::cout << "Error: are no absences for this student" << std::endl;
				Sleep(1000);
				system("cls");
				break;
			}
			else {
				int temp = 0;
				for (int temp = 0; temp < pCur->getStack()->getmSize(); temp++)
				{
					std::cout << temp << ".)   "<< *(pCur->getStack()->getpTop() + temp) << std::endl;
				}
				if (temp > 1)
				{
					std::cout << "Choose one of the above absences to edit:   ";
					std::cin >> temp;
				}
				else {
					temp = 0;
				}
				std::cout << std::endl << "Enter a new date below" << std::endl;
				getline(std::cin, newDate);
				*(pCur->getStack()->getpTop() + temp) = newDate;
				std::cout << "Successfully saved";
				system("cls");
				break;
			}
		}

		pCur = pCur->getpNext();
	}
}

/*
function: generateReport()
details: Gives user option to generate report for all students; showing only the most recent absence for each student (peek() operation)
		Or generate report for students with absences that match or exceed a number entered by the user.
input: 
output: 
*/
void appWrapper::generateReport()
{
	ListNode *pCur = mList.getpHead();
	int userChoice = 0;
	std::cout << "___________________Generate Report_______________________" << std::endl
		<< "1.   Generate all reports" << std::endl
		<< "2.   Generate reports by number of absences" << std::endl;
	std::cin >> userChoice;
	system("cls");
	if (userChoice == 1)
	{
		while (pCur != nullptr)
		{
			std::cout << pCur->getmID() << std::endl	//print students data to screen
				<< pCur->getmName() << std::endl
				<< pCur->getmEmail() << std::endl
				<< pCur->getUnits() << std::endl
				<< pCur->getmProgram() << std::endl
				<< pCur->getmLevel() << std::endl
				<< pCur->getStack()->peek() << std::endl << std::endl;

			pCur = pCur->getpNext();
		}
		system("pause");
		system("cls");
	}
	else {
		std::cout << "Enter a number of absences to search:  ";
		std::cin >> userChoice;
		while (pCur != nullptr)
		{
			if (pCur->getStack()->getmSize() >= userChoice)	//if student matches (or exceeds) absence search
			{
				std::cout << pCur->getmID() << std::endl	//print students data to screen
					<< pCur->getmName() << std::endl
					<< pCur->getmEmail() << std::endl
					<< pCur->getUnits() << std::endl
					<< pCur->getmProgram() << std::endl
					<< pCur->getmLevel() << std::endl
					<< pCur->getStack()->peek() << std::endl << std::endl;
			}
			pCur = pCur->getpNext();
		}
		system("pause");
		system("cls");
	}
}

/*
function: deleteList()
details: Recursively deletes List 
input: head of list to be deleted
output: N/A
*/
void appWrapper::deleteList(ListNode* pHead)
{
	if(pHead != nullptr)
	{
		deleteList(pHead->getpNext());
		delete(pHead);
	}
}