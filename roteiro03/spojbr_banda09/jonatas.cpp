#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_MUSICIANS = 100;

void inicializeMatrix(int matrix[MAX_MUSICIANS][MAX_MUSICIANS], int N);
void fillMatrices(int matrix[MAX_MUSICIANS][MAX_MUSICIANS], int N);

int main() {

    int N, M, X, Y, Z,
        counter = 0,
        matrix[MAX_MUSICIANS][MAX_MUSICIANS];
    std::cin >> N >> M;

    inicializeMatrix(matrix, N);

    while(counter < M)  {
        std::cin >> X >> Y >> Z;
        matrix[X-1][Y-1] = Z;
        matrix[Y-1][X-1] = Z;        
        counter++;
    }

    fillMatrices(matrix, N);

    return 0;
}

void inicializeMatrix(int matrix[MAX_MUSICIANS][MAX_MUSICIANS], int N)  {
    
    for(int i = 0; i < N; i++)  {
        for(int j = 0; j < N; j++)  {
            matrix[i][j] = 0;
        }
    }
}

void fillMatrices(int matrix[MAX_MUSICIANS][MAX_MUSICIANS], int N)  {
    int highestAffinity = 0,
        affinity = 0;
    std::vector<int> bands(3);
    bands[0] = 1;
    bands[1] = 2;
    bands[2] = 3;
    for(int i = 0; i < N; i++)  {
        for(int j = i + 1; j < N; j++)  {
            for(int k = j + 1; k < N; k++)  {
                affinity = matrix[i][j] + matrix[j][k] + matrix[k][i];
                if(affinity > highestAffinity)  {
                    highestAffinity = affinity;
                    bands[0] = i+1;
                    bands[1] = j+1;
                    bands[2] = k+1;
                }
            }
        }  
    }

    std::sort(bands.begin(), bands.end());
    std::cout << bands[0] << " " << bands[1] << " " << bands[2] << "\n";
}
