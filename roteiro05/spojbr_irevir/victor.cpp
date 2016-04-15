// O problema consiste em descobrir se há apenas um componente fortemente cone-
// xo no grafo formado pelas interseções e ruas. Isso foi feito por meio do al-
// goritmo de Kosaraju. Esse algoritmo realiza uma busca em profundidade no gra-
// fo a partir de um vértice arbitrário e salva os vértices em uma lista quando
// eles são fechados. Depois, é realizado outro DFS, partindo dos vértices na
// ordem inversa à da lista gerada previamente. Se esse DFS revela apenas um
// componente, há apenas um componente fortemente conectado no grafo.
//
// A implementação realizada é um pouco diferente. Não é necessário guardar a
// lista de fechamento de vértices. Basta notar se o vértice que abriu a busca
// é o mesmo a fechar por último. Depois, é realizado o DFS novamente partindo
// desse mesmo vértice, conferindo o mesmo critério.

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

    void setArc(int from, int to, bool value = true){
        if (matrix[from][to] != value){
            arcs += value + -1 * (not value);
            matrix[from][to] = value;
        }
    }

    Graph transposeSimple(){
        Graph t(vertices);
        for (int i = 0; i < vertices; i++){
            for (int j = 0; j < vertices; j++){
                if (matrix[i][j]){
                    t.setArc(j, i);
                }
            }
        }
        return t;
    }

    static Graph fromStdin(int n, int m){
        Graph g(n);
        for (int i = 0; i < m; i++){
            int from, to, num_ways; // num_ways == 1 -> one-way, 2 -> two-way
            std::cin >> from >> to >> num_ways;
            from--; to--; // these are 1-indexed in the test data
            g.setArc(from, to);
            if (num_ways == 2){
                g.setArc(to, from);
            }
        }
        return g;
    }

};

void recurseDFS(Graph &g, int v, std::vector<bool> &visited){
    visited[v] = true;

    for (int w = 0; w < g.vertices; w++){
        if (g.matrix[v][w] and not visited[w]){ // w is a successor of v
            recurseDFS(g, w, visited);
        }
    }
}

bool canReachAllFrom(Graph &g, int v){
    std::vector<bool> visited(g.vertices, false);
    recurseDFS(g, v, visited);
    return std::all_of(visited.begin(), visited.end(), [](bool b){return b;});
}

const int STARTING_VERTEX = 0; // There's always a vertex 0
bool isStronglyConnected(Graph &g){
    if (canReachAllFrom(g, STARTING_VERTEX)){
        Graph transpose = g.transposeSimple();
        // Since the procedure would have failed already if the first DFS
        // couldn't reach any of the vertices, it can safely be assumed that
        // the last vertex to be closed was the starting vertex. (Kosaraju)
        return canReachAllFrom(transpose, STARTING_VERTEX);
    }
    return false;
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
