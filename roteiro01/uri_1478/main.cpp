// O algoritmo para imprimir a matriz em si é simples e consiste de dois loops
// for para fazê-lo. O valor de cada célula é 1 + distância entre a célula e a
// diagonal principal da matriz, ou seja, 1 + |i - j|.

#include <cstdio> // printf, scanf
#include <algorithm> // min

int abs(int n){
    return n >= 0 ? n : n * (-1);
}

void print_matrix(int dim){
    for (int i = 1; i <= dim; i++){
        int cell_val;
        int j;
        for (j = 1; j <= dim - 1; j++){
            cell_val = 1 + abs(i - j);
            std::printf("%3d ", cell_val);
        }
        cell_val = 1 + abs(i - j);
        std::printf("%3d\n", cell_val);
    }
}

int main(){
    int m_size;
    while (true){
        std::scanf("%d", &m_size);
        if (m_size == 0){
            break;
        }

        print_matrix(m_size);
        std::printf("\n");
    }
}
