/*
Esse problema foi resolvido adicionando as arestas dos nós de maneira invertida:
a cada entrada de par de trabalhador e chefe, uma aresta era adicionada no sentido
de que o trabalhador possui tal chefe. Após isso, ao fazer um swap apenas a idade
é trocada, e um vetor de nomes é usado para manter referência de qual nome se refere
a qual trabalhador.
Após tudo isso, apenas um algoritmo de BFS (ou DFS iterativo, o recursivo dá
time limit) simples encontra o chefe de menor idade.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

struct Node;
typedef std::vector<Node> Graph;

struct Node {
    std::vector<int> bosses;
    int age;
    bool visited;

    Node(int _age) : age(_age), visited(false) { }
};

int youngestBossAge(Graph &g, int v) {
    std::queue<int> q;
    int age = 1000;

    g[v].visited = true;
    q.push(v);

    while(!q.empty()) {
        auto e = q.front();

        for(auto b : g[e].bosses) {
            if(g[b].visited)
                continue;

            if(g[b].age < age)
                age = g[b].age;

            g[b].visited = true;
            q.push(b);
        }

        g[e].visited = false;
        q.pop();
    }

    return age;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    for(;;) {
        Graph g;
        std::vector<int> names;
        int n, m, i;
        std::cin >> n >> m >> i;
        if(std::cin.eof())
            break;

        names.resize(n);
        for(int i = 0; i < n; ++i) {
            int age;
            std::cin >> age;
            g.emplace_back(age);
            names[i] = i;
        }

        while(m--) {
            int boss, worker;
            std::cin >> boss >> worker;
            --boss; --worker; // 0-index
            g[worker].bosses.push_back(boss);
        }

        while(i--) {
            char instr;
            std::cin >> instr;

            if(instr == 'T') {
                int a, b;
                std::cin >> a >> b;
                --a; --b; // 0-index

                std::swap(g[names[a]].age, g[names[b]].age);
                std::swap(names[a], names[b]);
            }
            else {
                int worker;
                std::cin >> worker;
                --worker; // 0-index

                if(g[names[worker]].bosses.empty()) {
                    std::cout << "*\n";
                }
                else {
                    std::cout << youngestBossAge(g, names[worker]) << "\n";
                }
            }
        }
    }

    return 0;
}
