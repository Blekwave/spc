/**
 * Esse problema foi resolvido fazendo todas as inversões para cada um dos
 * elementos da array de entrada, e contando a quantidade de inversões. Dado
 * o vetor v, indexado de 1 a N, para cada um dos elementos eram feitas a troca
 * de v[i] com v[v[i]] até o valor do elemento ser igual ao seu index. No final,
 * o vetor estará ordenado e o número de inversões contado.
 */

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    int t, n;

    std::cin >> t;
    while(t--) {
        std::cin >> n;
        std::vector<int> v(n+1);
        for(int i = 1; i <= n; ++i) {
            int a;
            std::cin >> a;
            v[i] = a;
        }

        size_t inv = 0;
        for(int i = 1; i <= n; ++i) {
            while(v[i] != i) {
                std::swap(v[v[i]], v[i]);
                ++inv;
            }
        }

        std::cout << inv << "\n";
    }

    return 0;
}
