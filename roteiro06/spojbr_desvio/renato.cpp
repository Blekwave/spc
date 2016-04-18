/**
 * Esse problema foi resolvido utilizando um simples algoritmo de caminho
 * mínimo entre o vértice inicial e o final (no caso, dijkstra).
 * O algoritmo de Dijkstra foi implementado usando uma Heap.
 * Para atender à condição de que caso o caminho chegar a um dos vértices
 * do caminho padrão esse caminho padrão deve ser seguido até o fim, ao
 * adicionar uma aresta ao grafo caso um dos vértices fosse do caminho padrão,
 * a aresta apenas seria adicionada caso o outro vértice fosse o próximo vértice
 * do caminho padrão, de modo que o grafo fica apenas com o caminho padrão nos
 * vértices do caminho padrão.
 */

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <functional>
#include <queue>
#include <vector>

struct Edge {
    size_t id;
    uintmax_t w;

    Edge(size_t _id, uintmax_t _w) : id(_id), w(_w) {  }
};

struct Node {
    uintmax_t d;
    bool visited;
    std::vector<Edge> adj;

    Node() : d(UINTMAX_MAX), visited(false) {  }
};

class CompareGreater {

public:
    constexpr bool operator()(const Node *l, const Node *r) const {
        return l->d > r->d;
    }
};

void dijkstra(std::vector<Node> &graph, size_t begin) {
    std::priority_queue<Node *, std::vector<Node *>, CompareGreater> h;

    graph[begin].d = 0;
    h.push(&graph[begin]);

    while(!h.empty()) {
        auto t = h.top();
        h.pop();
        if(t->visited)
            continue;
        t->visited = true;

        for(auto &e : t->adj) {
            if(t->d + e.w < graph[e.id].d) {
                graph[e.id].d = t->d + e.w;
                h.push(&graph[e.id]);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, c, k;

    for(;;) {
        std::cin >> n >> m >> c >> k;
        if(!n)
            break;

        std::vector<Node> graph;
        graph.resize(n);
        while(m--) {
            int u, v, p;
            std::cin >> u >> v >> p;

            if(u >= c || v == u + 1)
                graph[u].adj.emplace_back(v, p);
            if(v >= c || u == v + 1)
                graph[v].adj.emplace_back(u, p);
        }

        dijkstra(graph, k);
        std::cout << graph[c-1].d << "\n";
    }

    return 0;
}
