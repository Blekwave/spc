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
