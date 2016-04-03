/**
 * Esse problema foi resolvido através de usar uma árvore binária
 * para armazenar os votos, e iterar pela árvore binária para encontrar
 * o concorrente com mais votos. Isso funciona pois é necessário iterar
 * apenas pelo número de candidatos participantes, e não pelo número de
 * votos.
 * Foi utilizada a classe std::map, que é a implementação da STL de uma
 * árvore binária (normalmente uma Red-Black Tree).
 */

#include <map>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::map<int, int> db;
    int votes, num;

    std::cin >> votes;
    while(votes--) {
        std::cin >> num;
        ++db[num];
    }

    typedef std::map<int, int>::iterator It;
    It biggest = db.begin();
    for(It it = ++db.begin(); it != db.end(); ++it) { // assumes one vote.
        if(it->second > biggest->second)
            biggest = it;
    }

    std::cout << biggest->first;

    return 0;
}
