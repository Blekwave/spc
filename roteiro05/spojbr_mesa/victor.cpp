// O problema consiste em determinar se o grafo é bipartido ou não. Isso pode
// ser feito tentando colorir o grafo com duas cores alternadamente. Se isso
// se mostra impossível em algum momento, o grafo não pode ser bipartido.
// Na prática, a coloração foi realizada através de um DFS que, ao encontrar um
// novo vértice, colore esse vértice com a cor oposta à do vértice anterior. Se
// o algoritmo encontra um vértice já colorido com a mesma cor do vértice atual,
// isso significa que o novo vértice não pode ser colorido com a cor oposta do
// atual. Portanto, o grafo não é bipartido. Se o DFS termina sem problemas, o
// grafo é bipartido.


#include <iostream>
#include <vector>
#include <queue>

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

enum class Part {undefined, first, second};

const int STARTING_VERTEX = 0;

bool isBipartite(Graph &g){
    std::vector<Part> vertex_part(g.vertices, Part::undefined);
    std::queue<int> vertex_queue;
    vertex_queue.push(STARTING_VERTEX);
    vertex_part[STARTING_VERTEX] = Part::first;
    while (!vertex_queue.empty()){
        int u = vertex_queue.front();
        vertex_queue.pop();
        for (int v = 0; v < g.vertices; v++){
            if (g.matrix[u][v]){
                if (vertex_part[v] == vertex_part[u]){
                    return false; // not bipartite
                } else if (vertex_part[v] == Part::undefined){
                    vertex_queue.push(v);
                    if (vertex_part[u] == Part::first){
                        vertex_part[v] = Part::second;
                    } else {
                        vertex_part[v] = Part::first;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    int n, m, instance_num = 1;
    while (std::cin >> n){
        std::cin >> m;
        Graph g = Graph::fromStdin(n, m);
        bool result = isBipartite(g);
        std::cout << "Instancia " << instance_num << "\n"
                << (result ? "sim" : "nao") << "\n\n";
        instance_num++;
    }
    return 0;
}
