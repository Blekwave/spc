/*
 * Para resolver o problema, eu primeiramente descarto todas as caixas que
 * estão abaixo do nível da caixa 1. Após isso, olho para as caixas à esquerda
 * da caixa 1, e descarto todas as pilhas que estão à esquerda da primeira pilha
 * vazia. Faço o mesmo para as caixas à direita da caixa 1: descarto todas as
 * pilhas que estão à direita da primeira pilha vazia.
 * Com isso, o resultado final pode ser calculado por apenas:
 * min(caixasEsquerda, caixasDireita) + caixasPilhaCaixa1 - 1
 */

#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);

    for(;;) {
        int n, p;
        std::cin >> n >> p;
        if(!n) break;

        std::vector<int> sizes(p+1);
        int stack, pos;
        for(int i = 1; i <= p; ++i) {
            std::cin >> sizes[i];
            for(int j = 1; j <= sizes[i]; ++j) {
                int a;
                std::cin >> a;
                if(a == 1) {
                    stack = i;
                    pos = j;
                }
            }
        }

        for(int i = 1; i <= p; ++i)
            sizes[i] -= (pos - 1);

        int beg = 1, end = p;
        for(int i = stack - 1; i >= 1; --i) {
            if(sizes[i] <= 0) {
                beg = i + 1;
                break;
            }
        }
        for(int i = stack + 1; i <= p; ++i) {
            if(sizes[i] <= 0) {
                end = i - 1;
                break;
            }
        }

        int left = 0, right = 0;
        for(int i = beg; i < stack; ++i)
            if(sizes[i] > 0)
                left += sizes[i];
        for(int i = stack + 1; i <= end; ++i)
            if(sizes[i] > 0)
                right += sizes[i];

        int res = std::min(left, right) + (sizes[stack] - 1);

        std::cout << res << "\n";
    }

    return 0;
}
