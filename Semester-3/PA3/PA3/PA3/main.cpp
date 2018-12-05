/*
Freya Varez
9/25/2018
PA3
Details: Tests the efficiency of similar 'list' implementations 
	through the use of a myJosephus problem or 'Hot Potato'
*/

#include "ListMyJosephus.h"
#include "VectorMyJosephus.h"
#include <iostream>
#include <chrono>

int main() {
	int ans_M = 0, ans_N = 0;
	std::cout << "Enter M:  ";
	std::cin >> ans_M;
	std::cout << std::endl << "Enter N:  ";
	std::cin >> ans_N;
	system("cls"); //replace with unix equivalent

	ListMyJosephus list(ans_N, ans_M);	//initialize list 
	VectorMyJosephus vector(ans_N, ans_M);	//initlaize vector

	time_t start = 0;

	//Test List
	start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	list.testList();
	std::cout << "Time to execute <List>: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() - start
		<< " milliseconds" << std::endl;

	//Test Vector
	start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	vector.testVector();
	std::cout << "Time to execute <vector>: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() - start
		<< " milliseconds" << std::endl;

	return 0;
}