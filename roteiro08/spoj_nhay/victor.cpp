// O problema consiste em encontrar padrões em uma string de tamanho ilimitado.
// Para isso, a solução ideal envolve algoritmos de busca de padrão cujo
// pré-processamento independa do tamanho do texto.
// Nesta solução, foi implementado o algoritmo Knuth-Morris-Pratt (KMP). Sua
// implementação consiste em computar uma tabela de match parcial e, com ela,
// iterar pelo texto mantendo uma posição atual no padrão, que varia de acordo
// com os valores da tabela. O conceito principal utilizado é que podem existir
// no padrão prefixos que também são sufixos, que são a chave para não precisar
// voltar atrás nunca no texto em busca do padrão.

#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int prefixIsSuffix(char *needle, int size, int end){
    for (int i = 0, j = end - size; i < size; i++, j++){
        if (needle[i] != needle[j]){
            return false;
        }
    }
    return true;
}

vector<int> partialMatchTable(int n, char * needle){
    vector<int> pmt(n + 1);
    pmt[0] = -1;
    pmt[1] = 0;
    for (int i = 1; i < n; i++){
        int max_prefix = min(n - 1, pmt[i] + 1);
        int best_valid_prefix = 0;
        for (int prefix_size = max_prefix; prefix_size > 0; prefix_size--){
            if (prefixIsSuffix(needle, prefix_size, i + 1)){
                best_valid_prefix = prefix_size;
            }
        }
        pmt[i + 1] = best_valid_prefix;
    }
    return pmt;
}

void runCase(int n){
    char *needle = (char *) malloc(n + 1);
    getchar();
    fgets(needle, n + 1, stdin);
    getchar();
    vector<int> pmt = partialMatchTable(n, needle);
    char c;
    int i = 0;
    int j = 0;
    while (true){
        c = getchar();
        if (c == '\n'){
            break;
        }
        /* printf("i%d j%d c%c\n", i, j, c); */
        while (true){
            if (c == needle[j]){
                j++;
                if (j == n){
                    printf("%d\n", i - j + 1);
                    j = pmt[j];
                }
                break;
            } else if (j == 0) {
                break;
            } else {
                j = pmt[j];
            }
        }
        i++;
    }
    printf("\n");
    free(needle);
}

int main(){
    int n;
    while (scanf("%d", &n) && !feof(stdin)){
        runCase(n);
    }
    return 0;
}
