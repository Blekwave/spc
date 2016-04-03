// O algoritmo para imprimir a matriz em si é simples e consiste de dois loops
// for para fazê-lo. O valor de cada célula pode ser determinado considerando
// que há dois fatores que limitam o valor da célula: um limitador derivado da
// sua posição vertical e outro da sua posição horizontal. Ambos limitadores
// podem ser definidos como min(índice, max - índice + 1), sendo índice o ín-
// dice da linha/coluna e max o número de linhas/colunas. Finalmente, o valor
// da célula é o mínimo entre os dois limitadores.

#include <cstdio> // printf, scanf
#include <algorithm> // min

void print_matrix(int dim){
    for (int i = 1; i <= dim; i++){
        int height_min = std::min(i, dim - i + 1);
        int cell_val;
        int j;
        for (j = 1; j <= dim - 1; j++){
            cell_val = std::min(height_min, std::min(j, dim - j + 1));
            std::printf("%3d ", cell_val);
        }
        cell_val = std::min(height_min, std::min(j, dim - j + 1));
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
