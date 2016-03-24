/**
 * Esse problema foi resolvido utilizando sets: é uma estrutura de dados da
 * STL normalmente implementada como uma binary search tree.
 * Para resolver o problema, para cada DNA de entrada, esse DNA é ordenado
 * e adicionado ao set de DNAs. Esse set não aceita valores repetidos e,
 * portanto, se tentarmos adicionar uma string já existente ao set ele
 * simplesmente retornará uma referência à string já presente e não adicionará
 * mais nada. Desse modo, no final do loop o número de elementos no set é o
 * número de DNAs diferentes.
 */

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    while(std::cin >> n && n) {
        std::set<std::string> dnas;

        while(n--) {
            std::string str;
            std::cin >> str;
            std::sort(str.begin(), str.end());
            dnas.insert(str);
        }

        std::cout << dnas.size() << "\n";
    }

    return 0;
}

