/*
 * Para esse problema, foram usados dois vetores, um de largada e um de chegada.
 * Após ler os n elementos de cada vetor, eu iterei pelos veotres de checada e
 * largada, e quando encontrava um elemento no vetor de chegada igual ao de
 * largada, eu contava as diferenças de posições entre eles e fazia swaps para
 * mudar as posições de todos os outros carros, até igualar os dois vetores.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> largada, chegada;
    int n;

    for(;;) {
        std::cin >> n;
        if(std::cin.eof()) break;

        largada.clear();
        largada.resize(n);
        chegada.clear();
        chegada.resize(n);
        for(int i = 0; i < n; ++i)
            std::cin >> largada[i];
        for(int i = 0; i < n; ++i)
            std::cin >> chegada[i];

        int trocas = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(chegada[i] == largada[j]) {
                    while(j > i) {
                        std::swap(largada[j], largada[j - 1]);
                        ++trocas; --j;
                    }
                    break;
                }
            }
        }

        std::cout << trocas << "\n";
    }

    return 0;
}
