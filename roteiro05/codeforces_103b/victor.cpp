// A resolução do problema consiste em definir se o grafo tem apenas um ciclo

#include <iostream>
#include <vector>
#include <algorithm>

struct Graph {
    int vertices, edges;
    std::vector<std::vector<bool>> matrix;

    Graph(int n) : vertices(n), edges(0) {
        for (int i = 0; i < vertices; i++){
            std::vector<bool> row(vertices, false);
            matrix.push_back(row);
        }
    }

    void setEdge(int u, int v, bool value = true){
        if (matrix[u][v] != value){
            edges += value + -1 * (not value);
            matrix[u][v] = matrix[v][u] = value;
        }
    }

    static Graph fromStdin(int n, int m){
        Graph g(n);
        for (int i = 0; i < m; i++){
            int u, v;
            std::cin >> u >> v;
            g.setEdge(u - 1, v - 1); // the input for this problem is 1-indexed
        }
        return g;
    }

};

enum class Color {white, gray, black};

void recurseDFS(Graph &g, int v, int previous, int &cycle_count,
        std::vector<Color> &vertex_status){
    vertex_status[v] = Color::gray;
    for (int w = 0; w < g.vertices; w++){
        if (g.matrix[v][w]){
            if (vertex_status[w] == Color::white){
                recurseDFS(g, w, v, cycle_count, vertex_status);
            } else if (vertex_status[w] == Color::gray and w != previous){
                cycle_count++;
            }
        }
    }
    vertex_status[v] = Color::black;
}

const int STARTING_VERTEX = 0;
const int NOT_A_VERTEX = -1;
int countCycles(Graph &g){
    int cycle_count = 0;
    std::vector<Color> vertex_status(g.vertices, Color::white);
    recurseDFS(g, STARTING_VERTEX, NOT_A_VERTEX, cycle_count, vertex_status);
    if (std::any_of(vertex_status.begin(), vertex_status.end(),
                [](Color c){return c != Color::black;})){
        return -1;
    }
    return cycle_count;
}

int main(){
    int n, m;
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;

    Graph g = Graph::fromStdin(n, m);

    int cycle_count = countCycles(g);
    std::cout << (cycle_count == 1 ? "FHTAGN!" : "NO") << "\n";
    return 0;
}
