#include "Simulation.h"



Simulation::Simulation()
{
	initP = freeP = 0;
	itemNum = 0;
	insertedJobs = 0;
	running = true;
	
	
}

Simulation::Simulation(int proc_count)
{
	initP = freeP = proc_count;
	itemNum = 0;
	insertedJobs = 0;
	running = true;
}


Simulation::~Simulation()
{
}

bool Simulation::input(string fileName)
{
	file.open(fileName.c_str(), std::ios::in);

	if (file.is_open())
		return true;

	return false;
}

bool Simulation::checkWaitEmpty()
{
	return jobs.empty();
}

void Simulation::insert()
{
	int id, procs, ticks;
	string desc;
	id = itemNum;
	if (!file.eof()) {
		file >> desc;
		if (desc != "exit") {// checks for exit
			if (desc != "NULL" && desc != "") { // guard code incase it finds a null line
				file >> procs;
				file >> ticks;
				if (procs <= initP) //checks if the procs needed for the jobs is less than the total the machine has
				{
					
					jobs.push(Job(id, desc, procs, ticks*-1));
					std::cout << "ID: " << id << " was used\n";
					itemNum++;
				}
				else {
					std::cout << "\nFailed to insert job (" << desc << ") because there are not enough total processors\n\n\n";
				}
			}
			else { // guard code


				char thisIsAnnoying[300];
				file.getline(thisIsAnnoying, 300, '\n');
			}
		}
		else {
			running = false;
		}
	}
}

void Simulation::move()
{
	insertedJobs = 0;
	
	bool placed = false;
	do { // loop that checks if there are jobs in the wait queue to be moved to processing.
		placed = false;
		if (jobs.size() != 0) {
		
		Job temp = jobs.top();
		if (temp.getProCount() <= freeP) //checks if there are enough free procs if so moves it
			{
				temp.fixTicks();
				std::cout << "Job\n" << temp; 
				std::cout << "was submitted to the processing list\n\n\n\n";
				processing.push_back(temp);
				freeP -= temp.getProCount();
				jobs.pop();
				placed = true;
				insertedJobs++;
			}
		}
	} while (placed);
	
}

void Simulation::execute()
{
	list<Job>::iterator i = processing.begin();
	for (int j = 0; i != processing.end() && j < processing.size() - insertedJobs; i++, j++) {//runs only the item that were not inserted this tick
		i->runJob();
	}
}

void Simulation::cleanUp()
{
	list<Job>::iterator temp;
	if (processing.size() != 0) { // checks to make sure theres an item
		list<Job>::iterator i = processing.begin();
		if (processing.size() > 1) {//checks if the count is greater than one
			for (; i != processing.end(); i++) { // then it runs till it hits the end
				if (i->getTicks() <= 0) {
					
					if (i == processing.begin()) { //guard code in case the item getting removed is the first item
						temp = i;
						temp++;
						
					}
					std::cout << "Job\n" << "ID:\t\t" << i->getID() << "\nDescription:\t" << i->getDesc() << "\nProcessors:\t" << i->getProCount() << std::endl;
					std::cout << "got completed\n\n\n";
					freeP += i->getProCount();
					processing.erase(i);
					
					i = temp;
				}
				temp = i;
			}
		}

		else { // if only one item is in the list then it doesn't run the for loop, bug occurs with out it;
			if (i->getTicks() == 0) {

				std::cout << "Job\n" << "ID:\t\t" << i->getID() << "\nDescription:\t" << i->getDesc() << "\nProcessors:\t" << i->getProCount() << std::endl;
				std::cout << "got completed\n\n\n";
				freeP += i->getProCount();
				processing.erase(i);

			}
		}
	}
}

void Simulation::run()
{
	
	insert();
	move();
	execute();
	cleanUp();
}

void Simulation::start()
{
	bool fileInput = false;
if (initP == 0) { // only triggers if the constructor that required no input was used
		do { //makes sure the user puts in a damn integer
			std::cout << "Input the initial amount of processors to start with\n";
			initP = 0;

			std::cin >> initP;

			fileInput = true;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				initP = 0;
				fileInput = false;
			}


		} while (!fileInput);
	}
	freeP = initP;
	fileInput = false;
	do { // control loop to make sure the file gets opened to make sure the file exists;
		std::cout << "Input a file to read from where each line is in the form\t<job_desc> <n_procs> <n_ticks>\n";
		string name;

		std::cin >> name;

		if (input(name))
			fileInput = true;

	} while (!fileInput);


	

	while ((!file.eof() || !processing.empty() || !checkWaitEmpty()) && running) // makes sure it doesn't accidentally end prematurely.
		run();
	if (!running)
		std::cout << "hit an exit in the input file\n";
	std::cout << "finished running\n";
}
