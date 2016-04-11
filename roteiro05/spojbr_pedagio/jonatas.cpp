#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_NUM_CITIES = 50;

void initializeCities(int cities[MAX_NUM_CITIES][MAX_NUM_CITIES], int C);
void bfs(int cities[MAX_NUM_CITIES][MAX_NUM_CITIES], int C, int L, int P, int index);

int main()  {
	int C, E, L, P;
	int cities[MAX_NUM_CITIES][MAX_NUM_CITIES];
	int roadsCounter;
	int X, Y;
	int testIndex = 1;

	while(true)  {
		std::cin >> C >> E >> L >> P;
		if(C == 0 && E == 0 && L == 0 && P == 0)
			break;
		initializeCities(cities, C);
		roadsCounter = 0;
		while(roadsCounter < E)  {
			std::cin >> X >> Y;
			cities[X - 1][Y - 1] = 1;
			cities[Y - 1][X - 1] = 1;
			roadsCounter++;
		}
		bfs(cities, C, L, P, testIndex);
		testIndex++;
	}
}

void initializeCities(int cities[MAX_NUM_CITIES][MAX_NUM_CITIES], int C)  {
	for(int i = 0; i < C; i++)  {
		for(int j = 0; j < C; j++)  {
			cities[i][j] = 0;
		}
	}
}

void bfs(int cities[MAX_NUM_CITIES][MAX_NUM_CITIES], int C, int L, int P, int index)  {
	std::vector<int> possibleVisitCities(MAX_NUM_CITIES);
	std::vector<int> queue;
	int counter = 0;
	int currentCity;

	for(int i = 0; i < MAX_NUM_CITIES; i++)  {
		possibleVisitCities[i] = 0;
	}
	
	queue.push_back(L - 1);

	while(!queue.empty())  {
		currentCity = queue[0];
		for(int i = 0; i < C; i++)  {
			if(i != L - 1)  {
				if(cities[currentCity][i] == 1 && possibleVisitCities[i] == 0)  {
					possibleVisitCities[i] = possibleVisitCities[currentCity] + 1;
					queue.push_back(i);
				}
			}	
		}	
		queue.erase(queue.begin());
	}

	std::cout << "Teste " << index << "\n";
	for(int i = 0; i < MAX_NUM_CITIES; i++)  {
		if(possibleVisitCities[i] > 0 && possibleVisitCities[i] <= P)
			std::cout << i + 1 << " ";
	}
	std::cout << "\n\n";
}
