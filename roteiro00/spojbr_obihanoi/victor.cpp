// A estratégia ótima para resolver o problema da Torre de Hanoi envolve o
// seguinte algoritmo recursivo. Assumindo que os mastros sejam nomeados como
// A, B e C, um disco com n - 1 discos acima dele pode ser movido de A para C
// da seguinte maneira:
// - Move n - 1 discos de A para B
// - Move o disco de A para C
// - Move os n - 1 discos de B para C.
// O número de passos, expandindo a recorrência que surge, necessário para ter-
// minar o algoritmo equivale a 2^1 + 2^2 + ... + 2^(n - 1) = 2 ^ n - 1 passos.
//
// Dessa maneira, o programa escrito calcula o valor de 2 ^ n - 1.

#include <iostream>

long long exp2(int exponent){
    long long product = 1;
    for (int i = 0; i < exponent; i++){
        product *= 2;
    }
    return product;
}

int main(){
    int test_number = 1;
    while (true){
        int n;
        std::cin >> n;
        if (n == 0){
            break;
        }

        std::cout << "Teste " << test_number << "\n"
                  << exp2(n) - 1 << "\n\n";

        test_number++;
    }
}
