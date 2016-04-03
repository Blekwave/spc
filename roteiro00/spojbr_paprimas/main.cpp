/*

    Como o maior valor possível de entrada
    é uma string de 20 caracteres composta
    pela letra Z (valor 1040), podemos calcular
    todos os números primos até a raiz de 1040,
    e para testar a primalidade das strings recebidas
    basta tentar dividí-las por todos os números
    primos calculados.

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

const int MAXIMO = sqrt(1040);

int strToInt(std::string str, std::map<char, int> letras) {
    int soma = 0;
    for(char c : str) {
        soma += letras[c];
    }

    return soma;
}

bool primo(int num, std::vector<int> possib) {
    for(int i : possib) {
        if(i >= num)     return true;
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    int i, j;
    char atual;
    std::map<char, int> letras;

    for(i = 1, atual = 'a'; i < 27; i++, atual++) {
        letras[atual] = i;
    }
    for(atual = 'A'; i < 53; i++, atual++) {
        letras[atual] = i;
    }

    std::vector<int> primos;
    primos.push_back(2);
    for(i = 3; i < MAXIMO; i++) {
        for(j = 0; j < primos.size(); j++) {
            if(i % primos[j] == 0) break;
        }

        if(j == primos.size()) primos.push_back(i);
    }

    std::string palavra;

    while(std::cin >> palavra) {
        int valor = strToInt(palavra, letras);
        if(primo(valor, primos)) {
            std::cout << "It is a prime word.\n";
        } else {
            std::cout << "It is not a prime word.\n";
        }
    }

    return 0;
}
