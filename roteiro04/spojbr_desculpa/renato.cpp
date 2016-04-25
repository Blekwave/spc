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
