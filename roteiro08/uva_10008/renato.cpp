/**
 * Esse problema foi resolvido usando uma árvore binária de busca (std::map)
 * para armazenar a frequência dos caracteres. Após isso, os resultados eram
 * passados para uma outra árvore (std::set), nesse caso ordenada na ordem
 * pedida.
 * No final, é necessário apenas imprimir os resultados da segunda árvore.
 * Note que todos os caracteres são convertidos para uppercase antes de serem
 * adicionados na árvore e caracteres que não são letras são ignorados.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>

struct Letter {
    char c;
    int n;

    Letter(char _c, int _n = 0) : c(_c), n(_n) {  }
};

bool operator>(const Letter &l, const Letter &r) {
    if(l.n > r.n)
        return true;
    else if(l.n < r.n)
        return false;
    else if(l.c > r.c)
        return false;
    else
        return true;
}

int main() {
    std::map<char, int> frequency;
    int n;

    std::cin >> n;
    std::cin.ignore(2, '\n');
    while(n--) {
        std::string s;
        std::getline(std::cin, s);

        for(auto c : s) {
            if(!isalpha(c))
                continue;

            ++frequency[toupper(c)];
        }
    }

    std::set<Letter, std::greater<Letter>> letters;
    for(auto &e : frequency)
        letters.emplace(e.first, e.second);

    for(auto &e : letters)
        std::cout << e.c << " " << e.n << "\n";

    return 0;
}
