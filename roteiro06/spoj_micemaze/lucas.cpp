/*

Para resolver esse problema, precisamos do caminho mínimo entre todos os vértices,
onde cada vértice representa uma célula. Poderíamos utilizar Dijkstra para todos os
caminhos possíveis, mas para esse problema utilizamos o algoritmo de Floyd-Warshall,
que tem complexidade O(|V|³). Após a utilização desse algoritmo, passamos por todas
as posições na nova matriz de adjacências que representam arestas que terminam no
vértice onde se encontra a saída do labirinto.

*/

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

struct Graph {
    int vertices;
    std::vector< std::vector<unsigned int> > matrix;

    Graph(const int& n) : vertices(n) {
        for(int i = 0; i < vertices; i++) {
            std::vector<unsigned int> row(vertices, UINT_MAX);
            matrix.push_back(row);
        }
    }
};

void readGraph(Graph& g, int& edges) {
    int a, b, t;
    while(edges) {
        std::cin >> a >> b >> t;
        g.matrix[a-1][b-1] = t;
        edges--;
    }
}

void floydWarshall(Graph& g) {
    for (int i = 0; i < g.vertices; i++) {
        g.matrix[i][i] = 0;
    }

    for (int k = 0; k < g.vertices; k++) {
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                if(g.matrix[i][k] == UINT_MAX || g.matrix[k][j] == UINT_MAX) continue;
                g.matrix[i][j] = std::min(g.matrix[i][j], g.matrix[i][k] + g.matrix[k][j]);
            }
        }
    }
}

int main() {
    int n, e, t, m, result;
    result = 0;

    if(std::cin >> n >> e >> t >> m) {

        Graph g(n);
        readGraph(g, m);

        floydWarshall(g);

        for(int i = 0; i < n; i++) {
            if(g.matrix[i][e - 1] <= t) result++;
        }

        std::cout << result << "\n";
    }

    return 0;
}
