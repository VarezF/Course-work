#include "Header.h"
#include <iostream>

int main()
{
	int arr[10] = { 1,4,7,2,5,8,3,6,9 };
	std::cout << "original: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	mergeSort(arr, 10);

	std::cout << "Sorted: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}