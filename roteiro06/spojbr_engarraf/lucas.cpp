#include <climits>
#include <iostream>
#include <vector>
#include <queue>

typedef struct Graph {
    int vertices;
    std::vector<std::vector<int>> matrix;

    Graph(int n) : vertices(n) {
        for(int i = 0; i < vertices; i++) {
            std::vector<int> row(vertices, -1);
            matrix.push_back(row);
        }
    }
} Graph;

typedef struct Vertex {
    int idVertex, distance;

    Vertex(int id, int dist): idVertex(id), distance(dist) {};
} Vertex;

class Cmp {
    public:
    bool operator() (Vertex a, Vertex b) {
        return a.distance < b.distance;
    }
};

void readGraph(Graph& g, int edges) {
    int i, j, t;
    while(edges) {
        std::cin >> i >> j >> t;
        g.matrix[i-1][j-1] = t;
        edges--;
    }
}

int dijkstra(const Graph& g, int start, int end) {
    std::priority_queue<Vertex, std::vector<Vertex>, Cmp> heap;
    std::vector<bool> visited(g.vertices, false);
    std::vector<int> minDists(g.vertices, INT_MAX);

    heap.push(Vertex(start, 0));
    minDists[start] = 0;
    while(!heap.empty()) {
        Vertex curr = heap.top();
        heap.pop();
        visited[curr.idVertex] = true;

        if(curr.idVertex == end) return minDists[curr.idVertex];

        for(int i = 0; i < g.vertices; i++) {
            if(g.matrix[curr.idVertex][i] == -1 || visited[i]) continue;

            if(minDists[curr.idVertex] + g.matrix[curr.idVertex][i] < minDists[i])
                minDists[i] = minDists[curr.idVertex] + g.matrix[curr.idVertex][i];

            heap.push(Vertex(i, minDists[curr.idVertex]));
        }
    }

    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
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
