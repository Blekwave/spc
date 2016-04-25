#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_NODES = 50;
const int INFINITY = 100000;

void initializeStructures(int main_graph[MAX_NODES][MAX_NODES], int N);
void findMaxFlow(int main_graph[MAX_NODES][MAX_NODES], int N, int source, int sink);
bool bfsMaxFlow(int residual_graph[MAX_NODES][MAX_NODES], int N, int from[MAX_NODES], int source, int sink);
void determineConnectionsToCut(int main_graph[MAX_NODES][MAX_NODES], int residual_graph[MAX_NODES][MAX_NODES], int N, int source);

int main()  {
	int N, M,
		main_graph[MAX_NODES][MAX_NODES],
		X, Y, capacity,
		counter;

	while(true)  {
		std::cin >> N >> M;
		if(N == 0 && M == 0)
			break;
		initializeStructures(main_graph, N);
		counter = 0;
		while(counter < M)  {
			std::cin >> X >> Y >> capacity;
			main_graph[X - 1][Y - 1] += capacity;
			main_graph[Y - 1][X - 1] += capacity;
			counter++;
		}
		findMaxFlow(main_graph, N, 0, 1);
	}
	
}

void initializeStructures(int main_graph[MAX_NODES][MAX_NODES], int N)  {
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			main_graph[i][j] = 0;
		}
	}
}

void findMaxFlow(int main_graph[MAX_NODES][MAX_NODES], int N, int source, int sink)  {
	int residual_graph[MAX_NODES][MAX_NODES],
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
	}

	determineConnectionsToCut(main_graph, residual_graph, N, source);
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

void determineConnectionsToCut(int main_graph[MAX_NODES][MAX_NODES], int residual_graph[MAX_NODES][MAX_NODES], int N, int source)  {
	int final_graph[MAX_NODES][MAX_NODES];
	bool reached_by_source[MAX_NODES];
	std::vector<int> queue;

	for(int i = 0; i < N; i++)
		reached_by_source[i] = false;

	//Determines the final graph
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			if(main_graph[i][j] >= residual_graph[i][j])
				final_graph[i][j] = residual_graph[i][j];
			else
				final_graph[i][j] = residual_graph[i][j] - main_graph[i][j];
		}
	}

	//Determines the vertices that are reached by the source, using BFS, and stores in a array
	queue.push_back(source);
	reached_by_source[source] = true;
	while(!queue.empty())  {
		int current_vertex = queue[0];
		for(int i = 0; i < N; i++)  {
			if(final_graph[current_vertex][i] > 0 && !reached_by_source[i])  {
				queue.push_back(i);
				reached_by_source[i] = true;
			}
		}
		queue.erase(queue.begin());
	}
	
	//Determines the edges that connect a reached vertex with an unreached vertex and print its' coordinates
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			if(final_graph[i][j] > 0 && ((reached_by_source[i] && !reached_by_source[j]) || (!reached_by_source[i] && reached_by_source[j])))
				std::cout << i + 1 << " " << j + 1 << "\n";
		}
	}
	std::cout << "\n";
}
