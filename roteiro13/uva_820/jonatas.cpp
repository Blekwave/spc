#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_NODES = 100;
const int INFINITY = 100000;

void initializeStructures(int main_graph[MAX_NODES][MAX_NODES], int N);
void findMaxFlow(int main_graph[MAX_NODES][MAX_NODES], int N, int test_counter, int source, int sink);
bool bfsMaxFlow(int residual_graph[MAX_NODES][MAX_NODES], int N, int from[MAX_NODES], int source, int sink);

int main()  {
	int N,
		S, T, C,
		main_graph[MAX_NODES][MAX_NODES],
		X, Y, capacity,
		counter,
		test_counter = 1;

	while(true)  {
		std::cin >> N;
		if(N == 0)
			break;
		std::cin >> S >> T >> C;
		initializeStructures(main_graph, N);
		counter = 0;
		while(counter < C)  {
			std::cin >> X >> Y >> capacity;
			main_graph[X - 1][Y - 1] += capacity;
			main_graph[Y - 1][X - 1] += capacity;
			counter++;
		}
		findMaxFlow(main_graph, N, test_counter, S - 1, T - 1);
		test_counter++;
	}
	
}

void initializeStructures(int main_graph[MAX_NODES][MAX_NODES], int N)  {
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			main_graph[i][j] = 0;
		}
	}
}

void findMaxFlow(int main_graph[MAX_NODES][MAX_NODES], int N, int test_counter, int source, int sink)  {
	int max_bandwidth = 0,
		residual_graph[MAX_NODES][MAX_NODES],
		from[MAX_NODES];

	//At the begining, the residual graph is equal to the main graph
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			residual_graph[i][j] = main_graph[i][j];
		}
	}
	
	while(bfsMaxFlow(residual_graph, N, from, source, sink))  {
		int current_path = INFINITY;
		for(int i = sink; i != source; i = from[i])  {
			int current_vertex = from[i];
			current_path = std::min(current_path, residual_graph[current_vertex][i]);
		}
		//Updates residual graph edges values
		for(int i = sink; i != source; i = from[i])  {
			int current_vertex = from[i];
			residual_graph[current_vertex][i] -= current_path;
			residual_graph[i][current_vertex] += current_path;
		}
		max_bandwidth += current_path;
	}
	std::cout << "Network " << test_counter << "\nThe bandwidth is " << max_bandwidth << ".\n\n";
}

bool bfsMaxFlow(int residual_graph[MAX_NODES][MAX_NODES], int N, int from[MAX_NODES], int source, int sink)  {
	bool visited[MAX_NODES];
	std::vector<int> queue;

	for(int i = 0; i < MAX_NODES; i++)
		visited[i] = false;

	queue.push_back(source);
	visited[source] = true;
	from[source] = -1;

	//Finds a path in the residual graph. Returns true if the path is from the source to the sink. Otherwise, returns false
	while(!queue.empty())  {
		int current_vertex = queue[0];
		for(int i = 0; i < N; i++)  {
			if(!visited[i] && residual_graph[current_vertex][i] > 0)  {
				queue.push_back(i);
				from[i] = current_vertex;
				visited[i] = true;
			}
		}
		queue.erase(queue.begin());
	}

	if(visited[sink])
		return true;
	return false;
}
