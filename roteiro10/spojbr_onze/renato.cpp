/**
 * Esse problema utilizou-se do fato que se a soma alternada dos dígitos de um
 * número, da direita pra esquerda, for divisível por 11, então o número
 * original é divisível por 11.
 */

#include <iostream>
#include <string>
#include <cstdint>

int main() {

    for(;;) {
        std::string num;
        std::cin >> num;
        if(num == "0")
            break;

        intmax_t sum = 0;
        bool neg = false;
        for(auto it = num.rbegin(); it != num.rend(); ++it, neg = neg ? false : true)
            sum += (neg ? -1 : 1) * (*it - '0');

        if(sum % 11 == 0)
            std::cout << num << " is a multiple of 11.\n";
        else
            std::cout << num << " is not a multiple of 11.\n";
    }

    return 0;
}
