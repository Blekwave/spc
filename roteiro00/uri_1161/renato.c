/**
 * Calcula a soma de dois fatoriais através de uma função que calcula o
 * fatorial iterativamente, começando do maior número e multiplicando até o
 * menor deles.
 */

#include <stdio.h>

long long fac(int n) {
    long long val = 1;
    int i;

    for(i = n; i > 0; --i) {
        val *= i;
    }

    return val;
}

int main() {
    int m, n, r;

    for(;;) {
        r = scanf("%d%d", &m, &n);
        if(r != 2)
            break;

        printf("%lld\n", fac(m) + fac(n));
    }

    return 0;
}
