#include "Header.h"

int *mergeSort(int arr[], int size)
{
	if (size > 1) {
		int *p1, *p2;
		p1 = mergeSort(arr, size / 2);
		p2 = mergeSort(&arr[size / 2], (size / 2) - size % 2);
		for (int i = 0, j = 0, k = 0; k < size;)
		{
			if (i > size / 2) {
				for (; j < size / 2; j++) {
					arr[k] = p2[j];
				}
				break;
			}
			else if (j > size / 2 + 1) {
				for (; i < size / 2; i++) {
					arr[k] = p1[i];
				}
				break;
			}
			else if (p1[i] < p2[j]) {
				arr[k] = p1[i];
				i++;
				k++;
			}
			else {
				arr[k] = p2[j];
				j++;
				k++;
			}
		}
	}
	return arr;
}

int *cpyArray(int *destination, int *source, int size)
{

}