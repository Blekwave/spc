/*

    Fazemos a modelagem desse problema como uma rede de fluxo onde cada vértice
    é uma interseção e cada aresta é um corredor. A capacidade de todas as arestas
    é 1, permitindo assim que apenas um aluno da turma passe em cada corredor. Para
    evitar que os alunos se encontrem em vértices, duplicamos os vértices, criando
    para cada vértice X um X', sendo que as arestas que saem de X passam a sair de X'
    e a única aresta que sai de X vai para X' e tem capacidade 1. Dessa forma, para
    qualquer vértice X teremos as arestas entrando em X, saindo em X' e uma aresta
    ligando-os. Após criarmos o grafo dessa maneira, utilizamos op algoritmo de Ford-
    Fulkerson para calcular o fluxo máximo e gerar o grafo residual final. A partir do
    grafo residual obtemos o grafo com os fluxos ótimos. Caso o fluxo máximo seja
    menor que o número de alunos, é impossível que eles cheguem à sala sem se encontrar.
    Do contrário, listamos os caminhos disjuntos possíveis.

 */


#include <iostream>
#include <sstream>
#include <climits>
#include <string>
#include <queue>

const int SOURCE = 0;
const int SINK   = 1;

struct Graph {
    int vertices;
    std::vector< std::vector<int> > matrix;

    Graph(const int& n) : vertices(n * 2) {
        for(int i = 0; i < vertices; i++) {
            std::vector<int> row(vertices, -1);
            if(i < vertices/2) row[i + vertices/2] = 1;
            matrix.push_back(row);
        }

        // the first intersection can hold as many students as needed
        matrix[SOURCE][SOURCE + vertices/2] = INT_MAX;
    }
};

void readGraph(Graph& g) {
    int adj;
    std::string line;
    for(int i = (g.vertices/2) - 1; i < g.vertices; i++) {
        std::getline(std::cin, line);
        std::istringstream strm(line);

        while(strm >> adj) {
            g.matrix[i][adj - 1] = 1;
        }
    }
}

bool printPaths(Graph& g) {
    int curr = SOURCE;
    bool canMove;
    std::queue<int> result;
    result.push(SOURCE + 1);

    while(curr != SINK) {
        canMove = false;
        for(int i = 0; i < g.vertices/2; i++) {
            if(g.matrix[curr + g.vertices/2][i] > 0) {
                g.matrix[curr + g.vertices/2][i] = -1;
                curr = i;
                result.push(i + 1);
                canMove = true;
                break;
            }
        }
        if(!canMove) return false;
    }

    while(!result.empty()) {
        std::cout << result.front() << " ";
        result.pop();
    }
    std::cout << "\n";

    return true;
}

int findAugPath(Graph& g, Graph& residual) {
    std::vector<bool> visited(g.vertices, false);
    std::queue<int> q;
    q.push(SOURCE);
    visited[SOURCE] = true;
    std::vector<int> from(g.vertices, -1);
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
            if(next == SINK)
                sinkFound = true;
        }
    }

    where = SINK;
    int pathCap = INT_MAX;

    while(from[where] > -1) {
        prev = from[where];
        pathCap = std::min(pathCap, residual.matrix[prev][where]);
        where = prev;
    }

    where = SINK;

    while(from[where] > -1) {
        prev = from[where];
        residual.matrix[prev][where] -= pathCap;
        residual.matrix[where][prev] += pathCap;
        where = prev;
    }

    if(pathCap == INT_MAX) return 0;
    return pathCap;
}

int maximumFlow(Graph& g) {
    Graph residual(g.vertices);
    for(int i = 0; i < g.vertices; i++) {
        for(int j = 0; j < g.vertices; j++) {
            residual.matrix[i][j] = g.matrix[i][j];
        }
    }
    int result = 0, extraCap = -1;
    while(extraCap != 0) {
        extraCap = findAugPath(g, residual);
        result += extraCap;
    }

    // we calculate the graph of flows
    for(int i = 0; i < g.vertices; i++) {
        for(int j = 0; j < g.vertices; j++) {
            if(g.matrix[i][j] != -1 && residual.matrix[i][j] != -1) {
                g.matrix[i][j] -= residual.matrix[i][j];
            }
        }
    }

    return result;
}

int main() {
    int K, N, adj, maxStudents;
    int nTest = 1;

    while(true) {
        std::cin >> K >> N;
        if(K == 0) break;

        Graph g(N);
        readGraph(g);

        maxStudents = maximumFlow(g);

        std::cout << "Case " << nTest << ":\n";
        if(maxStudents < K) {
            std::cout << "Impossible\n";
        } else {
            while(printPaths(g) && --K) {};
        }
        
        std::cout << "\n";
        nTest++;
    }

    return 0;
}