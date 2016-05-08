#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int TYPES_OF_COINS = 5;
const int MAX_VALUE = 30000;

void initializeMatrix(long long int matrix[TYPES_OF_COINS][MAX_VALUE + 1], int number);
void coin_change(long long int matrix[TYPES_OF_COINS][MAX_VALUE + 1], int number, std::vector<int> coins);

int main()  {
	int number;
	long long int matrix[TYPES_OF_COINS][MAX_VALUE + 1];
	std::vector<int> coins(TYPES_OF_COINS);
	
	coins[0] = 1;
	coins[1] = 5;
	coins[2] = 10;
	coins[3] = 25;
	coins[4] = 50;

	while(true)  {
		std::cin >> number;
		if(std::cin.eof())
			break;
		initializeMatrix(matrix, number);
		coin_change(matrix, number, coins);
	}
}

void initializeMatrix(long long int matrix[TYPES_OF_COINS][MAX_VALUE + 1], int number)  {
	for(int i = 0; i < TYPES_OF_COINS; i++)  {
		for(int j = 0; j < number + 1; j++)  {
			//Initializes the first row with 1s
			if(i == 0)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}
}

void coin_change(long long int matrix[TYPES_OF_COINS][MAX_VALUE + 1], int number, std::vector<int> coins)  {
	for(int i = 1; i < TYPES_OF_COINS; i++)  {
		for(int j = 0; j < number + 1; j++)  {
			if(j < coins[i])  {
				matrix[i][j] = matrix[i - 1][j];
			}
			else
				matrix[i][j] = matrix[i - 1][j] + matrix[i][j - coins[i]];
		}
	}

	if(matrix[TYPES_OF_COINS - 1][number] == 1)
		std::cout << "There is only 1 way to produce " << number << " cents change.";
	else
		std::cout << "There are " << matrix[TYPES_OF_COINS - 1][number] << " ways to produce " << number << " cents change.";
	std::cout << "\n";
}
