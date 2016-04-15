/**
 * Para resolver esse problema apenas usei busca binária (a função
 * std::lower_bound é implementada com busca binária) para encontrar os
 * resultados.
 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    vector<int>::iterator it;
    int n, q, val;

    scanf("%d%d", &n, &q);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &val);
        numbers.push_back(val);
    }

    for(int i = 0; i < q; ++i) {
        scanf("%d", &val);
        it = lower_bound(numbers.begin(), numbers.end(), val);

        if(it == numbers.end())
            puts("-1");
        else if(*it != val)
            puts("-1");
        else
            printf("%d\n", (int) (it - numbers.begin()));
    }

    return 0;
}
