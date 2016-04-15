// A solução para o problema consiste em verificar o maior valor dentre as
// somas de cada coluna e de cada linha. O maior valor encontrado corresponde
// ao maior número de minhocas que pode ser coletado.

#include <iostream>
#include <vector>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> columns(m);
    int max_sum = 0;
    for (int i = 0; i < n; i++){
        int row_sum = 0;
        for (int j = 0; j < m; j++){
            int temp;
            std::cin >> temp;
            columns[j] += temp;
            row_sum += temp;
        }
        if (row_sum > max_sum){
            max_sum = row_sum;
        }
    }
    for (int col_sum : columns){
        if (col_sum > max_sum){
            max_sum = col_sum;
        }
    }
    std::cout << max_sum << '\n';
}
