#include "VectorMyJosephus.h"

VectorMyJosephus::VectorMyJosephus() {	//constructor
	this->circ = std::vector<Person>();
	this->M = 0;
	this->N = 0;
}

VectorMyJosephus::VectorMyJosephus(int N, int M) {
	Person *pMem = nullptr;
	this->circ = *new std::vector<Person>;
	for (int i = 0; i < N; i++) {
		pMem = new Person(i);
		this->circ.push_back(*pMem);	//stack overflow?? *pMem out of scope?
	}
	this->N = N;
	this->M = M;
	this->loser = 0;
}

VectorMyJosephus::~VectorMyJosephus() {
	this->circ.~vector();	//call vector destructor
}

void VectorMyJosephus::init(int N, int M) {
	Person *pMem = nullptr;
	for (int i = 0; i < N; i++) {
		pMem = new Person;
		pMem->setPosition(i);
		this->circ.push_back(*pMem);
	}
}

//	makes the circle empty 
void VectorMyJosephus::clear() {
	this->circ.clear();	//clears list
}

//	prints the number of people still playing the game (i.e., not yet eliminated) 
int VectorMyJosephus::currentSize() {
	return this->circ.size();
}

//	returns true if circle is empty
bool VectorMyJosephus::isEmpty() {
	return this->circ.empty();
}

// eliminates the next person as per the game's rule
void VectorMyJosephus::eliminateNext() {
	this->loser = (M + this->loser) % this->currentSize();
	std::vector<Person>::iterator current = this->circ.begin();
	std::advance(current, this->loser);
	std::cout << "Loser: " << current->getPosition() << std::endl;
	this->circ.erase(current);
}

// prints the current content of circle in sequence starting from the person with the least position number
void VectorMyJosephus::printAll() {
	std::cout << "Remaining: {";
	for (Person p : this->circ) {
		std::cout << p.getPosition() << "  ";
	}
	std::cout << "}" << std::endl << std::endl;
}

void VectorMyJosephus::testVector() {
	for (int i = 0; i < this->N - 1; i++) {
		this->eliminateNext();
		printAll();
	}
	std::cout << "Winner: " << this->circ.begin()->getPosition() << std::endl;
}