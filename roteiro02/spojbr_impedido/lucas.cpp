/*

    Armazenamos a distância do gol para o atacante
    mais próximo do gol e em seguida armazenamos a
    distância para todos os defensores. Ordenamos
    as distâncias dos defensores e comparamos a
    posição do penúltimo defensor com a do atacante
    mais próximo do gol.

*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MAXDIST 10000

int main() {
    int A, D;

    while(true) {
        std::cin >> A >> D;
        if(A == 0) break;

        int menorDistAtacante, dist, i;
        menorDistAtacante = MAXDIST;
        for(i = 0; i < A; i++) {
            std::cin >> dist;
            if(dist < menorDistAtacante) {
                menorDistAtacante = dist;
            }
        }

        std::vector<int> defensores;
        for(i = 0; i < D; i++) {
            std::cin >> dist;
            defensores.push_back(dist);
        }
        std::sort(defensores.begin(), defensores.end());

        if(menorDistAtacante < defensores[1]) std::cout << "Y\n";
        else                                  std::cout << "N\n";
    }
}
