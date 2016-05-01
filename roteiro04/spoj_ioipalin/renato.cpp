/*
 * Para resolver esse problema, eu calculo a Longest Common Subsequence (LCS)
 * da string de entrada com ela mesma invertida. Com isso, eu tenho o maior
 * número de caracteres que deram match em sequência. Portanto, o número de
 * caracteres que eu teria que mudar para tornar a string um palíndromo é
 * n - LCS, em que n é o tamanho da string.
 */

#include <algorithm>
#include <cstdio>

const int MaxSize = 5001;

int main() {
    int n;
    char str[MaxSize], rev[MaxSize];
    int bef[MaxSize], curr[MaxSize];

    scanf("%d", &n);
    scanf("%s", str);
    for(int i = 0; i < n; ++i)
        rev[i] = str[n-i-1];

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(str[i-1] == rev[j-1])
                curr[j] = 1 + bef[j-1];
            else
                curr[j] = std::max(bef[j], curr[j-1]);
        }

        std::swap(bef, curr);
    }

    printf("%d\n", n - bef[n]);

    return 0;
}
