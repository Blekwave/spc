#include <iostream>
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

int find_augpath(Graph& g, Graph& residual) {
    std::queue q;
    
}

int maximumFlow(Graph g) {
    Graph residual(g.vertices);
    int result = 0;
    while(1) {
        int extraCap = find_augpath(g, residual);
        result += extraCap;
        if(extraCap == 0)
            return result;
    }
}

int main() {
    // we have 27 uppercase and 27 lowercase letters
    Graph g(54);

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

    int maxFlow = maximumFlow(g);

    std::cout << maxFlow << "\n";

    return 0;
}