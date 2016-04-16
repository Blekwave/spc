/*

Para resolver esse problema de caminho mínimo, utilizamos o algoritmo de Dijkstra.
Nosso grafo possui n + 2 vértices, onde n é o número de pilares, pois temos um vértice
para o inicio do caminho e outro para o acampamento. O algoritmo calcula apenas o
caminho mínimo, e não as pontes pelas quais teremos que passar.

*/


#include <climits>
#include <iostream>
#include <vector>
#include <queue>

struct Graph {
    int vertices;
    std::vector< std::vector<int> > matrix;

    Graph(const int& n) : vertices(n) {
        for(int i = 0; i < vertices; i++) {
            std::vector<int> row(vertices, -1);
            matrix.push_back(row);
        }
    }
};

struct Vertex {
    int idVertex, distance;

    Vertex(const int& id, const int& dist): idVertex(id), distance(dist) {};
};

struct Cmp {
    bool operator() (const Vertex& a, const Vertex& b) {
        return a.distance > b.distance;
    }
};

void readGraph(Graph& g, int& edges) {
    int i, j, t;
    while(edges) {
        std::cin >> i >> j >> t;
        g.matrix[i][j] = t;
        g.matrix[j][i] = t;
        edges--;
    }
}

int dijkstra(const Graph& g, const int& start, const int& end) {
    std::priority_queue<Vertex, std::vector<Vertex>, Cmp> pq;
    std::vector<bool> visited(g.vertices, false);
    std::vector<int> minDists(g.vertices, INT_MAX);

    pq.push(Vertex(start, 0));
    minDists[start] = 0;
    while(!pq.empty()) {
        Vertex curr = pq.top();
        pq.pop();
        visited[curr.idVertex] = true;

        if(curr.idVertex == end) return minDists[curr.idVertex];

        for(int i = 0; i < g.vertices; i++) {
            if(g.matrix[curr.idVertex][i] == -1 || visited[i]) continue;

            if(minDists[curr.idVertex] + g.matrix[curr.idVertex][i] < minDists[i]) {
                minDists[i] = minDists[curr.idVertex] + g.matrix[curr.idVertex][i];

                pq.push(Vertex(i, minDists[i]));
            }
        }
    }

    return -1;
}

int main() {
    int n, m;

    std::cin >> n >> m;

    Graph g(n + 2);
    readGraph(g, m);

    std::cout << dijkstra(g, 0, n + 1) << "\n";

    return 0;
}
