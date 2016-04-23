#include <iostream>
#include <queue>

const int NUM_LETTERS = 54;

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

void readGraph(Graph& g, int nEdges, std::map<char, int> charToIndex) {
    char from, to;
    int indFrom, indTo, flow;
    while(nEdges) {
        std::cin >> from >> to >> flow;
        indFrom = charToIndex[from];
        indTo   = charToIndex[to];
        if(g.matrix[indFrom][indTo] == -1) {
            g.matrix[indFrom][indTo] = flow;
        } else {
            g.matrix[indFrom][indTo] += flow;
        }
        nEdges--;
    }
}

int find_augpath(Graph& g, Graph& residual, std::map<char, int> charToIndex) {
    std::vector<bool> visited(NUM_LETTERS, -1);
    std::queue<int> q;
    q.push('A');
    visited[charToIndex['A']] = true;
    std::vector<int> from(NUM_LETTERS, -1);

    while(!q.empty()) {
        int curr = q.top();
        q.pop();

        for(int weight : g.matrix[curr]) {

        }
    }

}

int maximumFlow(Graph g, std::map<char, int> charToIndex) {
    Graph residual(g.vertices);
    for(int i = 0; i < g.vertices; i++) {
        for(int j = 0; j < g.vertices; j++) {
            residual.matrix[i][j] = g.matrix[i][j];
        }
    }
    int result = 0;
    while(1) {
        int extraCap = find_augpath(g, residual, charToIndex);
        result += extraCap;
        if(extraCap == 0)
            return result;
    }
}

int main() {
    // we have 27 uppercase and 27 lowercase letters
    Graph g(NUM_LETTERS);

    // we map the possible characters to indexes on the graph
    std::map<char, int> charToIndex;
    int i = 0;
    for(char c = 'a'; c <= 'z'; c++, i++) {
        charToIndex[c] = i;
    }
    for(char c = 'A'; c <= 'Z'; c++, i++) {
        charToIndex[c] = i;
    }

    int N;
    std::cin >> N;

    readGraph(g, N, charToIndex);

    int maxFlow = maximumFlow(g, charToIndex);

    std::cout << maxFlow << "\n";

    return 0;
}