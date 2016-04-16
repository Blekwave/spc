/*

Esse problema é um caso simples de caminho mínimo. Para resolvê-lo, utilizamos
o algoritmo de Dijkstra, utilizando uma fila de prioridades para armazenar os
vertices a visitar para realizar o relaxamento, e repetindo o processo até que
tenhamos a menor distância até a posição onde queremos chegar. Não precisamos
do caminho que leva à menor distância, precisamos apenas do valor dessa distância.

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
        g.matrix[i-1][j-1] = t;
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
    int n, m, start, end;
    while(true) {
        std::cin >> n >> m;
        if(n == 0) break;

        Graph g(n);
        readGraph(g, m);
        std::cin >> start >> end;

        std::cout << dijkstra(g, start-1, end-1) << "\n";
    }
    return 0;
}
