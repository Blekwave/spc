/*
 * Para resolver esse problema, basta ir somando 1/i, 1/(i+1), 1/(i+2), etc...
 * começando de i = 2, até essa soma ser > c. O resultado procurado é i-2.
 */

#include <iostream>
#include <cfloat>

int main() {
    std::ios_base::sync_with_stdio(false);

    for(;;) {
        float c;
        std::cin >> c;
        if(c < 0.01)
            break;

        float sum = 0.0f;
        int i;
        for(i = 2; sum < c; ++i)
            sum += (float) 1 / i;

        std::cout << i-2 << " card(s)\n";
    }

    return 0;
}
