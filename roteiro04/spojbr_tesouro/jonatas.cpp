#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

const int MAX_VALUE = 10000;
const int MAX_N = 100;

void initializeMatrix(bool matrix[MAX_N][MAX_VALUE], int N, int bestSolution, int initialValue);
void subsetSum(bool matrix[MAX_N][MAX_VALUE], int N, int bestSolution, std::vector<int> items, int testCounter);

int main()  {
	int X, Y, N, V,
		counter,
		testCounter = 1,
		solution, bestSolution;
	bool matrix[MAX_N][MAX_VALUE];
	std::vector<int> items;

	while(true)  {
		std::cin >> X >> Y >> N;
		if(X == 0 && Y == 0 && N == 0)
			break;
		counter = 0;
		solution = 0;
		while(counter < N)  {
			std::cin >> V;
			solution += V;
			items.push_back(V);
			counter++;
		}
		std::sort(items.begin(), items.end());
		bestSolution = (std::abs(X - Y) + solution);
		if(bestSolution % 2 != 0)
			std::cout << "Teste " << testCounter << "\n" << "N" << "\n";
		else  {
			bestSolution = bestSolution/2;
			initializeMatrix(matrix, N, bestSolution, items[0]);
			subsetSum(matrix, N, bestSolution, items, testCounter);
		}
		items.clear();
		testCounter++;
	}
	return 0;
}

void initializeMatrix(bool matrix[MAX_N][MAX_VALUE], int N, int bestSolution, int initialValue)  {
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < bestSolution + 1; j++)  {
			if(j == 0)
				matrix[i][j] = true;
			else
				matrix[i][j] = false;
		}
		if(i == 0)
			matrix[i][initialValue] = true;
	}
}

void subsetSum(bool matrix[MAX_N][MAX_VALUE], int N, int bestSolution, std::vector<int> items, int testCounter)  {
	bool subsetFound = false;
	for(int i = 1; i < N; i++)  {
		for(int j = 0; j < bestSolution + 1; j++)  {
			if(j < items[i])
				matrix[i][j] = matrix[i - 1][j];
			else  
				matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - items[i]];
			if(j == bestSolution && matrix[i][j])  {
				subsetFound = true;
				break;
			}
		}
	}
	std::cout << "Teste " << testCounter << "\n";
	if(subsetFound)
		std::cout << "S" << "\n";
	else
		std::cout << "N" << "\n";
}
