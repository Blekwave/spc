#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_HOUSES = 100;
const int INFINITE = 101; //Cause 100 is the highest value of Z

struct tab  {
	int index;
	std::vector<int> neighbors;
};

struct edge  {
	int x;
	int y;
};

void initializeStructures(tab tabs[MAX_HOUSES], int tents[MAX_HOUSES][MAX_HOUSES], bool visited[MAX_HOUSES], int N);
void prim(tab tabs[MAX_HOUSES], int tents[MAX_HOUSES][MAX_HOUSES], bool visited[MAX_HOUSES], int N, int testCounter);
void printAnswer(std::vector<edge> edges, int N, int testCounter);

int main()  {
	int N, M,
		X, Y, Z,
		counter, 
		testCounter = 1;
	int tents[MAX_HOUSES][MAX_HOUSES];
	bool visited[MAX_HOUSES];
	tab tabs[MAX_HOUSES];

	while(true)  {
		std::cin >> N >> M;
 		if(N == 0)
			break;
		initializeStructures(tabs, tents, visited, N);
		counter = 0;
		while(counter < M)  {
			std::cin >> X >> Y >> Z;
			tents[X - 1][Y - 1] = Z;
			tents[Y - 1][X - 1] = Z;
			tabs[X - 1].neighbors.push_back(Y - 1);
			tabs[Y - 1].neighbors.push_back(X - 1);
			counter++;
		}
		prim(tabs, tents, visited, N, testCounter);
		std::cout << "\n";
		testCounter++;
	}

	return 0;
}

void initializeStructures(tab tabs[MAX_HOUSES], int tents[MAX_HOUSES][MAX_HOUSES], bool visited[MAX_HOUSES], int N)  {
	for(int i = 0; i < N; i++)  {
		tabs[i].index = i;
		visited[i] = false;
		for(int j = 0; j < N; j++)  {
			tents[i][j] = 0;
		}
	}
}

void prim(tab tabs[MAX_HOUSES], int tents[MAX_HOUSES][MAX_HOUSES], bool visited[MAX_HOUSES], int N, int testCounter)  {
	std::vector<edge> edges;
	std::vector<tab> visitedTabs;
	tab currentTab = tabs[0];
	tab nextTab;
	int lowestValue;
	edge currentEdge; 

	while(edges.size() < (N - 1))  {
		visitedTabs.push_back(currentTab);
		visited[currentTab.index] = true;
		lowestValue = INFINITE;
		for(int i = 0; i < visitedTabs.size(); i++)  {
			currentTab = visitedTabs[i];
			for(int j = 0; j < visitedTabs[i].neighbors.size(); j++)  {				
				if(tents[currentTab.index][currentTab.neighbors[j]] > 0 && tents[currentTab.index][currentTab.neighbors[j]] < lowestValue)  {
					if(!visited[currentTab.neighbors[j]])  {
						lowestValue = tents[currentTab.index][currentTab.neighbors[j]];
						nextTab = tabs[currentTab.neighbors[j]];
						currentEdge.x = currentTab.index;
						currentEdge.y = currentTab.neighbors[j];
					}
				}
			}
		}

		edges.push_back(currentEdge);
		tents[currentEdge.x][currentEdge.y] = -1;
		tents[currentEdge.y][currentEdge.x] = -1; //Removes the edge from the tab matrix
		currentTab = nextTab;
	}

	printAnswer(edges, N, testCounter);
}

void printAnswer(std::vector<edge> edges, int N, int testCounter)  {
	std::cout << "Teste " << testCounter << "\n";
	edge currentEdge;
	for(int i = 0; i < N - 1; i++)  {
		currentEdge = edges[i];
		if(currentEdge.x < currentEdge.y)
			std::cout << currentEdge.x + 1 << " " << currentEdge.y + 1 << "\n";
		else
			std::cout << currentEdge.y + 1 << " " << currentEdge.x + 1 << "\n";
	}
}