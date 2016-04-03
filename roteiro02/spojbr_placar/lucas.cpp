/*
    Armazenamos as notase os nomes dos alunos em
    um vetor de tuplas. Em seguida usamos a função
    sort da STL para ordenar o vetor. Para isso usamos
    uma função que ordena os alunos em ordem crescente
    de nota e descrescente de nomes.
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<std::string, int> aluno;

bool ordenacao(aluno a, aluno b) {
    if(a.second < b.second) return true;
    if(a.second > b.second) return false;

    if(a.first > b.first) return true;
    return false;
}

int main() {
    int numAlunos, instancia = 1;

    while(std::cin >> numAlunos) {

        std::vector<aluno> alunos;
        std::string nome;

        int nota, i;
        for(i = 0; i < numAlunos; i++) {
            std::cin >> nome >> nota;
            alunos.push_back(aluno(nome, nota));
        }
        std::sort(alunos.begin(), alunos.end(), ordenacao);

        std::cout << "Instancia " << instancia << "\n";
        std::cout << alunos[0].first << "\n\n";

        instancia++;
    }

    return 0;
}
