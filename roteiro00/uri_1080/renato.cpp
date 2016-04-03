/**
 * Para resolver esse problema, eu usei duas variáveis para salvar o maior
 * número e a sua posição, e sempre que encontrasse um número maior eu salvo
 * esses dados. Inicializo o maior número como INT_MIN, então sempre vai ser
 * possível achar um maior.
 */

#include <iostream>
#include <climits>

int main() {
    int val, big = INT_MIN, pos = 1;

    for(int i = 1; i <= 100; ++i) {
        std::cin >> val;
        if(val > big) {
            big = val;
            pos = i;
        }
    }

    std::cout << big << "\n" << pos << "\n";

    return 0;
}

