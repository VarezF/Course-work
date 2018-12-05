#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

//algorithms maxSubSum1, maxSubSum2, maxSubSum3 and maxSubSum4 taken from:
//(https://learn.wsu.edu/bbcswebdav/pid-2768577-dt-content-rid-90657869_1/courses/2018-FALL-PULLM-CPT_S-223-4105-LEC/CptS223_PA2_Fall2018%281%29.pdf)

//cubic max contiguous subsequence sum algorithm 
int maxSubSum1(const std::vector<int> & a) {
	int maxSum = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = i; j < a.size(); ++j) {
			int thisSum = 0;

			for (int k = i; k <= j; ++k)
				thisSum += a[k];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}

//Quadratic maximum contiguous subsequence sum algorithm
int maxSubSum2(const std::vector<int> & a) {
	int maxSum = 0;
	
	for (int i = 0; i < a.size(); ++i) {
		int thisSum = 0;
		for (int j = i; j < a.size(); ++j) {
			thisSum += a[j];
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int max3(int maxLeftSum, int maxRightSum, int borderSum) {
	return std::max({ maxLeftSum, maxRightSum, borderSum });
}

//recursive maximum contiguous subsequence  sum algorithm
//finds maximum sum in subarray spanning a[left...right]. 
//does not attempt to find actual best sequance
int maxSumRec(const std::vector<int> & a, int left, int right) {
	if (left == right)	//base case
		if(a[left] > 0)
			return a[left];
		else return 0;

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; --i) {
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; ++j) {
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}
	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + rightBorderSum);
}

//Driver for divide-and-conquer maximum contiguous subsequence sum algorithm
int maxSubSum3(const std::vector<int> & a) {
	return maxSumRec(a, 1, a.size() - 1);
}

//Linear-time maximum contiguous subsequence sum algorithm
int maxSubSum4(const std::vector<int> & a) {
	int maxSum = 0, thisSum = 0;

	for (int j = 0; j < a.size(); ++j) {
		thisSum += a[j];

		if (thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
}

void populateVector(std::vector<int> *values, char *filename) {
	std::ifstream infile;
	infile.open(filename);
	char temp1[3];
	int value = 0;

	while (!infile.eof()) {
		infile >> temp1;
		if (temp1[0] == '\0')
			break;
		value = atoi(temp1);
		values->push_back(value);
	}
}

int main(int argc, char** argv) {
	if (argc > 2) {
		std::cout << "Error, please provide input file pathway" << std::endl;
		return 0;
	}
	std::vector<int> values;
	populateVector(&values, argv[1]);
	int max1 = 0, max2 = 0, max3 = 0, max4 = 0;

	time_t start = 0, total1 = 0, total2 = 0, total3 = 0, total4 = 0;

	start = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	max1 = maxSubSum1(values);
	total1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() - start;

	start = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	max2 = maxSubSum2(values);
	total2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() - start;

	start = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	max3 = maxSubSum3(values);
	total3 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() - start;

	start = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	max4 = maxSubSum4(values);
	total4 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() - start;

	std::cout << "Algorithm 1:   " << total1 << " microseconds" << std::endl
		<< "Algorithm 2:   " << total2 << " microseconds" << std::endl
		<< "Algorithm 3:   " << total3 << " microseconds" << std::endl
		<< "Algorithm 4:   " << total4 << " microseconds" << std::endl;
}