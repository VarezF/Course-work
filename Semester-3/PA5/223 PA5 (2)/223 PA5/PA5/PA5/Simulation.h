#pragma once
#include <queue>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include "Job.h"

using std::priority_queue;
using std::string;
using std::fstream;
using std::list;
class Simulation
{
public:
	Simulation();

	//use this constructor input 0 if you want to be told to put in a p count
	Simulation(int proc_count);
	~Simulation();

	
	//runs the program
	//done comments are so lame to write
	//it's like writing a story no one wants to read
	void start();



private:
	priority_queue<Job> jobs;//wait queue
	list<Job> processing;

	int initP; //initial processors
	int freeP; //free processors
	int insertedJobs; //stores how many jobs were inserted this tick
	fstream file; //stores the file to be read from
	unsigned itemNum; //stores the current job ID
	bool running;

	//runs the all the steps required to do the simulation
	void run(); 

	//will insert one item at a time from the file
	void insert(); 

	//will move as many items as free processors exist
	//move jobs -> processing
	void move();

	//will run all items that were NOT inserted this tick
	void execute();

	//will find all items that have 0 tick counts left for completion and remove them from the list
	void cleanUp();

	//tests if the string can open a file
	//returns true if the file opens
	//returns false if the file fails to open
	bool input(string fileName);

	//checks if items are in the wait queue
	//returns true if the queue has no items in it
	//returns false if the queue has items in it
	bool checkWaitEmpty();
};

