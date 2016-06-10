// O problema consiste em determinar o intervalo mínimo de tempo para o qual,
// usando duas ampulhetas, é possível medir com precisão uma certa duração.
// O valor objetivo pode ser determinado através do mínimo entre duas equações
// de congruência, sendo k a duração a ser medida e p e q a duração das duas
// ampulhetas:
// min(i * p, j * q) | i * p === k mod q,
//                     j * q === k mod p

#include <iostream>
#include <algorithm>

// i * j === k mod m
int find_i(int j, int k, int m){
    int i = 0;
    while (i * j % m != k){
        i++;
    }
    return i;
}

int main(){
    int time, hg1, hg2;
    std::cin >> time >> hg1 >> hg2;

    int hg1_time = hg1 * find_i(hg1, time, hg2);
    int hg2_time = hg2 * find_i(hg2, time, hg1);
    std::cout << std::min(hg1_time, hg2_time);

    return 0;
}
