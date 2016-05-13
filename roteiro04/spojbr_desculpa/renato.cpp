/*
 * O algoritmo utiliza um vetor para armazenar as frases e uma tabela para
 * calcular a PD. Inicialmente a tabela é inicializada toda com zeros, e é
 * preenchida do início ao fim seguindo a equação de recorrência abaixo:
 *      t[i][j] = t[i-1][j] if phrases[i].numCharacters is bigger than j
 * else t[i][j] = max(t[i-1][j], phrases[i].numSorrys + t[i-1][j - phrases[i].numCharacters]).
 *
 * No final, o resultado da PD está em t[numPhrases][cardSize].
 */

#include <iostream>
#include <algorithm>
#include <vector>

struct Frase {
    size_t numCarac;
    size_t numDesc;
};

int main() {
    size_t comp, numFrases;
    size_t tabela[51][10001] = { { 0 } };
    Frase frases[51] = { {0, 0} };
    size_t teste = 0;

    for(;;) {
        std::cin >> comp >> numFrases;

        if(comp == 0 && numFrases == 0)
            break;

        for(size_t i = 1; i <= numFrases; ++i) {
            std::cin >> frases[i].numCarac >> frases[i].numDesc;
        }

        std::cout << "Teste " << ++teste << "\n";

        for(size_t i = 1; i <= numFrases; ++i) {
            for(size_t j = 0; j <= comp; ++j) {
                if(frases[i].numCarac > j) {
                    tabela[i][j] = tabela[i - 1][j];
                }
                else {
                    tabela[i][j] = std::max(tabela[i - 1][j],
                        frases[i].numDesc + tabela[i - 1][j - frases[i].numCarac]);
                }
            }
        }

        std::cout << tabela[numFrases][comp] << "\n\n";
    }

    return 0;
}
