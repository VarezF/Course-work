#pragma once
#include "List.h"
#include "ListNode.h"
#include <fstream>

class appWrapper {
public:
	appWrapper();	//constructor
	~appWrapper();	//destructor

	List getlist();	//getters

	void displayMenu();
	void import();
	void load();
	void store();
	void markAbsences();
	void editAbsences();
	void generateReport();
	void deleteList(ListNode *pHead);	//recursively deletes list 

private:
	List mList;
};