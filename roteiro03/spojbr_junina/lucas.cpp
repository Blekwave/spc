/*
    Para cada caso de teste, construímos um grafo onde cada
    aluno é um vértice, e para dois alunos A e B, só existe
    uma aresta entre eles caso A e B não tenham inimizade.
    A seguir, entre todos os grupos testamos quais podem
    existir sem que pessoas inimigas fiquem juntas. Não
    testamos todas as possibilidades, pois se temos dois
    alunos A e B que tem inimizade, não há necessidade de
    testar nenhum grupo que contenha ambos os alunos.
    Para percorrer os grupos utilizamos um processo de backtracking,
    onde as escolhas consistem em adicionar ou não determinado aluno.
    Armazenamos as linhas da matriz de adjacência do grafo e
    os grupos testados como um número inteiro de 32 bits, e
    utilizamos operações bitwise para operar sobre esses valores.
    Por fim, é importante notar que da forma como foi construído,
    esse algoritmo consiste em encontrar a maior clique em um grafo.
*/

#include <iostream>
#include <vector>
#include <cstdint>

const int MAXSIZE = 20;

void fillGraph(std::vector<uint32_t> &graph, const int &size) {
    for(int i = 0; i < size; i++) {
        graph[i] = UINT32_MAX;
    }
}

int maxClique(const std::vector<uint32_t> &graph, uint32_t currClique, const int startAt, const int &size) {
    for(int i = 0; i < startAt; i++) {
        if((currClique & (1 << i)) && ((currClique & graph[i]) != currClique)) return 0;
    }

    if(startAt == size) return __builtin_popcount(currClique);
    
    currClique     |= (1 << startAt);
    int sizeWith    = maxClique(graph, currClique, startAt + 1, size);
    currClique     &= ~(1 << startAt);
    int sizeWithout = maxClique(graph, currClique, startAt + 1, size);
    return (sizeWith > sizeWithout ? sizeWith : sizeWithout);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int i, disliked, cliqueSize, N, nTest = 1;
    std::vector<uint32_t> graph(MAXSIZE);
    fillGraph(graph, MAXSIZE);

    while(true) {
        std::cin >> N;
        if(N == 0) break;

        std::cout << "Teste " << nTest << "\n";

        for(i = 0; i < N; i++) {
            while(std::cin >> disliked && disliked != 0) {
                graph[disliked - 1] &= ~(1 << i);
            }
        }

        cliqueSize = maxClique(graph, 0, 0, N);

        std::cout << cliqueSize << "\n\n";
        fillGraph(graph, N);
        nTest++;
    }

    return 0;
}
