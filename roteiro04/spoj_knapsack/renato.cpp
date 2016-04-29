/*
 * Para esse problema, uso uma array bidimensional indexada pelo número de itens
 * e pelo valor desses itens, e preencho a array usando programação dinâmica.
 * No final, a resposta é o último elemento da matriz.
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

const int MaxSize = 2001;
std::array<std::array<int, MaxSize>, MaxSize> table;

struct Item {
    int size, value;
    Item(int _s, int _v) : size(_s), value(_v) {  }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::vector<Item> items;
    int s, n, a, b;

    std::cin >> s >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        items.emplace_back(a, b);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= s; ++j) {
            if(items[i-1].size > j) {
                table[i][j] = table[i-1][j];
            }
            else {
                table[i][j] = std::max(table[i-1][j],
                        table[i-1][j - items[i-1].size] + items[i-1].value);
            }
        }
    }

    std::cout << table[n][s] << "\n";

    return 0;
}
