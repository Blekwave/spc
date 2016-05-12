// O problema consiste em determinar quantas palavras diferentes são
// correspondentes a uma série de dígitos que correspondem a caracteres do
// alfabeto numericamente (de 1 a 26).
// O cálculo disso consiste na execução de um algoritmo de programação
// dinamica que checa, para cada dígito lido, se ele é um dígito válido
// individualmente e se ele e o dígito anterior formam um caractere válido.
// O dígito é válido individualmente se ele é diferente de 0, e ele é válido
// conjuntamente com o anterior se ambos formam algum valor de 01 a 26.
// Um vetor é utilizado para armazenar o número máximo de combinações até uma
// determinada posição. Esse valor equivale para v[i] à soma de v[i - 1] se o
// dígito atual é válido individualmente e v[i - 2] se o atual e o prévio
// formam um caractere válido conjuntamente.
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string s;
    while (std::cin >> s){
        if (s == "0"){
            break;
        }

        if (s.size() == 1){
            std::cout << "1\n";
            continue;
        }

        std::vector<long long> v = {1,
            (int)(s[1] > '0') + (s[0] == '2' && s[1] <= '6' || s[0] == '1')
        };
        for (unsigned i = 2; i < s.size(); i++){
            long long p = (s[i] > '0') * v[i - 1] +
                          (s[i - 1] == '2' && s[i] <= '6' || s[i - 1] == '1') * v[i - 2];
            v.push_back(p);
        }

        std::cout << v.back() << "\n";
    }
    return 0;
}
