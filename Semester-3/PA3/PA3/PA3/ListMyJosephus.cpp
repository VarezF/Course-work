#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus() {
	this->circ = std::list<Person>();
	this->M = 0;
	this->N = 0;
}

ListMyJosephus::ListMyJosephus(int N, int M) {
	Person *pMem = nullptr;
	this->circ = std::list<Person>();
	for (int i = 0; i < N; i++) {
		pMem = new Person;
		pMem->setPosition(i);
		this->circ.push_back(*pMem);
	}
	this->N = N;
	this->M = M;
	this->loser = 0;
}

ListMyJosephus::~ListMyJosephus() {
	this->circ.~list();	//call list destructor
}

void ListMyJosephus::init(int N, int M) {
	Person *pMem = nullptr;
	for (int i = 0; i < N; i++) {
		pMem = new Person;
		pMem->setPosition(i);
		this->circ.push_back(*pMem);
	}
}

//	makes the circle empty 
void ListMyJosephus::clear() {
	this->circ.clear();	//clears list
}

//	prints the number of people still playing the game (i.e., not yet eliminated) 
int ListMyJosephus::currentSize() {
	return this->circ.size();
}

//	returns true if circle is empty
bool ListMyJosephus::isEmpty() {
	return this->circ.empty();
}

// prints the current content of circle in sequence starting from the person with the least position number
void ListMyJosephus::printAll() {
	std::cout << "Remaining: {";
	for (Person p : this->circ) {
		std::cout << p.getPosition() << "  ";
	}
	std::cout << "}" << std::endl << std::endl;
}
// eliminates the next person as per the game's rule
void ListMyJosephus::eliminateNext() {
	this->loser = (M + this->loser) % this->currentSize();
	std::list<Person>::iterator current = this->circ.begin();
	std::advance(current, this->loser);
	std::cout << "Loser: " << current->getPosition() << std::endl;
	this->circ.erase(current);
}

void ListMyJosephus::testList() {
	for (int i = 0; i < this->N - 1; i++) {
		this->eliminateNext();
		printAll();
	}
	std::cout << "Winner: " << this->circ.begin()->getPosition() << std::endl
		<< "______________________________________________________________" << std::endl;
}