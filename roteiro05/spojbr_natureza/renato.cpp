/*
Esse problema foi resolvido usando um map de strings (nome do animal) para
um set de outras strings (animais aos quais o animal é ligado na cadeia
alimentar). O nome dos animais iniciais não é necessário, e portanto essa parte
da entrada é ignorada. Após isso, para cada aresta do grafo lida é adicionada
uma entrada no gravo em ambas as direções, de modo a criar um grafo não
direcionado.
Para a contagem da cadeia alimentar, uma busca em profundidade simples foi
usada. Essa busca removia do grafo cada nó por onde passava, enquanto aumentava
a contagem de nós. Desse modo, todo o subgrafo era removido do grafo inicial,
gerando a contagem de membros da cadeia. Essa operação era repetida até o grafo
ficar vazio e, finalmente, a maior das cadeias era impressa.
 */

#include <iostream>
#include <map>
#include <string>
#include <set>

typedef std::map<std::string, std::set<std::string>> Graph;
typedef std::pair<std::string, std::set<std::string>> NodePair;

int removeChain(Graph &g, Graph::iterator it) {
    int size = 1;
    std::set<std::string> edges{std::move(it->second)};
    g.erase(it);

    for(auto animal : edges) {
        auto aIt = g.find(animal);

        if(aIt != g.end())
            size += removeChain(g, aIt);
    }

    return size;
}

int main() {

    for(;;) {
        int c, r;
        std::cin >> c >> r;
        if(!c && !r) {
            break;
        }

        Graph g;
        while(c--) {
            std::string s;
            std::cin >> s; // Ignore
        }

        while(r--) {
            std::string c1, c2;
            std::cin >> c1 >> c2;
            g[c1].insert(c2);
            g[c2].insert(c1);
        }

        int biggest = 1;
        while(!g.empty())
            biggest = std::max(biggest, removeChain(g, g.begin()));

        std::cout << biggest << "\n";
    }

    return 0;
}
