#include <iostream>
#include <utility>
#include <algorithm>

const int MAX_NUMBERS = 10000;
const int NUMBER_OF_PLAYERS = 2;

void defineMaxPoints(int N, long long int cards[MAX_NUMBERS]);
void initializeMatrix(int N, long long int aux_matrix[NUMBER_OF_PLAYERS][MAX_NUMBERS]);

int main()  {
	int N;
	long long int cards[MAX_NUMBERS];

	while(true)  {
		std::cin >> N;
		if(std::cin.eof())
			break;
		for(int i = 0; i < N; i++)  {
			std::cin >> cards[i];
		}
		defineMaxPoints(N, cards);
	}

	return 0;
}

void initializeMatrix(int N, long long int aux_matrix[NUMBER_OF_PLAYERS][MAX_NUMBERS])  {
	//Initializes the aux_matrix
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++)  {
		for(int j = 0; j < N; j++)  {
			aux_matrix[i][j] = 0;
		}
	}
}

void defineMaxPoints(int N, long long int cards[MAX_NUMBERS])  {
	long long int aux_matrix[NUMBER_OF_PLAYERS][MAX_NUMBERS];
	
	initializeMatrix(N, aux_matrix);

	for(int i = 0; i < N; i++)  {
		for(int j = 0; j + i < N; j++)  {
			if(i % 2 == 1)  //Verifies if the current i is even or odd
				aux_matrix[0][j] = std::max(aux_matrix[1][j + 1] + cards[j], aux_matrix[1][j] + cards[j + i]);
			else
				aux_matrix[1][j] = std::min(aux_matrix[0][j + 1], aux_matrix[0][j]);
		}
	}
	std::cout << aux_matrix[0][0] << "\n";
}
