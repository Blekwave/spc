#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_LINES_COLUMNS = 10;

struct node  {
	int i, j, cost, value;
};

void initializeStructures(int N, int M);
void bfs(node initialPosition, int N, int M, std::vector<node> queue);
node nextPosition(node currentPosition, int N, int M, int index);

node cave[MAX_LINES_COLUMNS][MAX_LINES_COLUMNS];
int visited[MAX_LINES_COLUMNS][MAX_LINES_COLUMNS];

int main()  {
	int N, M;
	std::vector<node> queue;
	node initialPosition;

	std::cin >> N >> M;
	initializeStructures(N, M);
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < M; j++)  {
			std::cin >> cave[i][j].value;
			if(cave[i][j].value == 3)  {
				initialPosition.i = i;
				initialPosition.j = j;
				initialPosition.cost = 0;
				cave[i][j].cost = 0;
			}
		}
	}

	bfs(initialPosition, N, M, queue);

	return 0;
}

void initializeStructures(int N, int M)  {
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < M; j++)  {
			cave[i][j].i = i;
			cave[i][j].j = j;
			cave[i][j].cost = 1;
			cave[i][j].value = 0;
			visited[i][j] = 0;
		}
	}
}

void bfs(node initialPosition, int N, int M, std::vector<node> queue)  {
	queue.push_back(initialPosition);
	visited[initialPosition.i][initialPosition.j] = 1;
	while(!queue.empty())  {
		node currentNode = queue[0];
		if(cave[currentNode.i][currentNode.j].value == 0)
			break;
		for(int i = 0; i < 4; i++)  {
			node nearNode = nextPosition(currentNode, N, M, i);
			if(nearNode.i != -1 && nearNode.j != -1)  {
				if(visited[nearNode.i][nearNode.j] == 0 && cave[nearNode.i][nearNode.j].value != 2)  {
					cave[nearNode.i][nearNode.j].cost = cave[currentNode.i][currentNode.j].cost + 1;
					visited[nearNode.i][nearNode.j] = 1;
					queue.push_back(nearNode);
				}
			}
		}
		queue.erase(queue.begin());
	}
	std::cout << cave[queue[0].i][queue[0].j].cost << "\n";
}

node nextPosition(node currentPosition, int N, int M, int index)  {
	node invalid_position;
	invalid_position.i = -1;
	invalid_position.j = -1;

	if(index == 0)  {
		if(currentPosition.i - 1 >= 0)
			return cave[currentPosition.i - 1][currentPosition.j];
		return invalid_position;
	}
	if(index == 1)  {
		if(currentPosition.j + 1 < M)
			return cave[currentPosition.i][currentPosition.j + 1];
		return invalid_position;
	}
	if(index == 2)  {
		if(currentPosition.i + 1 < N)
			return cave[currentPosition.i + 1][currentPosition.j];
		return invalid_position;
	}
	if(index == 3)  {
		if(currentPosition.j - 1 >= 0)
			return cave[currentPosition.i][currentPosition.j - 1];
		return invalid_position;
	}
	return invalid_position;
}
