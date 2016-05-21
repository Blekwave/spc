/**
 * Esse problema foi resolvido através do simples cálculo do MDC entre os dois
 * números de entrada usando o algoritmo de euclides.
 */

#include <iostream>

int gcd(int a, int b) {
    int c;

    while(b) {
        c = b;
        b = a % b;
        a = c;
    }

    return a;
}

int main() {
    int n;

    std::cin >> n;
    while(n--) {
        int a, b;

        std::cin >> a >> b;
        std::cout << gcd(a, b) << "\n";
    }

    return 0;
}
