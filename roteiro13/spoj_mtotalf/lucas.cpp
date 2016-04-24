/*

    Recebemos os canos e montamos o grafo. Caso tenhamos mais de um cano entre
    dois estábulos, somamos as capacidades dos canos. Mantemos um mapeamento das
    letras dos canos para os índices dos vértices no grafo. Após esse procedimento,
    utilizamos o algoritmo de Ford-Fulkerson para obter o fluxo máximo de água entre
    o celeiro A e o celeiro Z, e exibimos o valor desse fluxo.

 */


#include <climits>
#include <iostream>
#include <queue>
#include <map>

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

int findAugPath(Graph& g, Graph& residual, std::map<char, int> charToIndex) {
    std::vector<bool> visited(NUM_LETTERS, false);
    std::queue<int> q;
    q.push(charToIndex['A']);
    visited[charToIndex['A']] = true;
    std::vector<int> from(NUM_LETTERS, -1);
    bool sinkFound = false;
    int where, next, prev;

    while(!q.empty() && !sinkFound) {
        where = q.front();
        q.pop();

        for(next = 0; next < g.vertices; next++){
            int weight = g.matrix[where][next];
            if(weight == -1 || visited[next] || residual.matrix[where][next] <= 0) continue;

            q.push(next);
            visited[next] = true;
            from[next] = where;
            if(next == charToIndex['Z'])
                sinkFound = true;
        }
    }

    where = charToIndex['Z'];
    int pathCap = INT_MAX;

    while(from[where] > -1) {
        prev = from[where];
        pathCap = std::min(pathCap, residual.matrix[prev][where]);
        where = prev;
    }

    where = charToIndex['Z'];

    while(from[where] > -1) {
        prev = from[where];
        residual.matrix[prev][where] -= pathCap;
        residual.matrix[where][prev] += pathCap;
        where = prev;
    }

    if(pathCap == INT_MAX) return 0;
    return pathCap;
}

int maximumFlow(Graph g, std::map<char, int> charToIndex) {
    Graph residual(g.vertices);
    for(int i = 0; i < g.vertices; i++) {
        for(int j = 0; j < g.vertices; j++) {
            residual.matrix[i][j] = g.matrix[i][j];
        }
    }
    int result = 0, extraCap = -1;
    while(extraCap != 0) {
        extraCap = findAugPath(g, residual, charToIndex);
        result += extraCap;
    }

    return result;
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