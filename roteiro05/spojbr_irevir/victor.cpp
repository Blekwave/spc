// O problema consiste em descobrir se há apenas um componente fortemente cone-
// xo no grafo formado pelas interseções e ruas.

#include <iostream>
#include <vector>
#include <algorithm>

struct Graph {
    int vertices, arcs;
    std::vector<std::vector<bool>> matrix;

    Graph(int n) : vertices(n), arcs(0) {
        for (int i = 0; i < vertices; i++){
            std::vector<bool> row(vertices, false);
            matrix.push_back(row);
        }
    }

    static Graph fromStdin(int n, int m){
        Graph g(n);
        for (int i = 0; i < m; i++){
            int from, to, num_ways; // num_ways == 1 -> one-way, 2 -> two-way
            std::cin >> from >> to >> num_ways;
            from--; to--; // these are 1-indexed in the test data
            g.matrix[from][to] = true;
            arcs++;
            if (num_ways == 2){
                g.matrix[to][from] = true;
                arcs++;
            }
        }
        return g;
    }

};

void recurseDFS(Graph &g, int v, std::vector<bool> &visited, int &last_visited){
    visited[v] = true;
    last_visited = v;

    for (int w = 0; w < g.vertices; w++){
        if (g.matrix[v][w] and not visited[w]){ // w is a successor of v
            recurseDFS(g, w, visited, last_visited);
        }
    }
}

bool canReachAllFrom(Graph &g, int v, int &last_visited){
    std::vector<bool> visited(g.vertices, false);
    recurseDFS(g, v, visited, last_visited);
    return std::all_of(visited.begin(), visited.end(), [](bool b){return b;});
}

bool isStronglyConnected(Graph &g){
    int last_visited, dummy;
    return canReachAllFrom(g, 0, last_visited) and
        canReachAllFrom(g, last_visited, dummy);
}

int main(){
    int n, m;
    std::cout.sync_with_stdio(false);
    std::cin.sync_with_stdio(false);

    while (true){
        std::cin >> n;
        if (n == 0){
            break;
        }
        std::cin >> m;

        Graph g = Graph::fromStdin(n, m);

        bool result = isStronglyConnected(g);
        std::cout << (int) result << "\n";

    }
}
