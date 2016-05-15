/**
 * Esse problema foi resolvido com um simples algoritmo: se o número de páginas
 * for menor que 6, o resultado é modificaod para 6. Se for maior que 20, o
 * resultado é modificado para 20. Caso ficar nesse meio termo, a quantidade
 * de o's a imprimir é (numPaginas - 4).
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
        int n, p, l, i;

        for(;;) {
                cin >> n >> p;
                if(n == 0 && p == 0)
                        break;

                l = n / p;
                if(n % p) l++;

                if(l < 6) l = 6;
                else if(l > 20) l = 20;
                l -= 4;

                cout << "P";
                for(i = 0; i < l; ++i)
                        cout << "o";
                cout << "dle\n";
        }

        return 0;
}
