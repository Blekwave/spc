/**
 * Esse problema foi resolvido através ler todas as cartas para um vetor,
 * ordená-lo e, então, usar std::next_permutation() para gerar as permutações.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> cards;
    int n;

    for(;;) {
        std::cin >> n;
        if(!n) break;

        cards.clear();
        for(int i = 0; i < n; ++i) {
            int val;
            std::cin >> val;
            cards.push_back(val);
        }
        std::sort(cards.begin(), cards.end());

        do {
            std::cout << cards[0];
            for(int i = 1; i < n; ++i)
                std::cout << " " << cards[i];
            std::cout << "\n";
        } while(std::next_permutation(cards.begin(), cards.end()));
    }

    return 0;
}
