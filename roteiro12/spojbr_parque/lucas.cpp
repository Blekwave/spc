/*

Para a resolução desse problema, utilizamos programação dinâmica para encontrar
a menor subsequência comum às duas sequências genéticas. Ao fim desse processo,
podemos construir uma solução pegando as letras específicas de cada palavra na
ordem, alternando com um elemento da LCS sempre que ele for encontrado nas duas
palavras. Dessa forma as letras que podem ser usadas nas duas palavras ao mesmo
tempo não são repetidas, e obtemos a menor "supersequência" das duas strings.

*/

#include <iostream>
#include <vector>

std::string findSeq(std::vector< std::vector<int> > matrix, std::string fstSeq, std::string sndSeq, int i, int j) {
    if(i == 0 || j == 0) {
        return "";
    } else if(fstSeq[i-1] == sndSeq[j-1]) {
        return findSeq(matrix, fstSeq, sndSeq, i-1, j-1) + fstSeq[i-1];
    } else {
        if(matrix[i][j-1] > matrix[i-1][j]) { 
            return findSeq(matrix, fstSeq, sndSeq, i, j-1);
        } else {
            return findSeq(matrix, fstSeq, sndSeq, i-1, j);
        }
    }
}

std::string LCS(std::string fstSeq, std::string sndSeq) {
    int N = fstSeq.size(),
        M = sndSeq.size();

    std::vector< std::vector<int> > matrix;

    for(int i = 0; i <= N; i++) {
        matrix.push_back(std::vector<int>(M + 1, 0));
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(fstSeq[i-1] == sndSeq[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
        }
    }

    return findSeq(matrix, fstSeq, sndSeq, N + 1, M + 1);
}

std::string shortestSuperSeq(std::string fstSeq, std::string sndSeq) {
    int N = fstSeq.size(),
        M = sndSeq.size();

    std::string subseq = LCS(fstSeq, sndSeq),
                result = "";

    int ind1 = 0, ind2 = 0;
    for(int i = 0; i < subseq.size(); i++) {
        while(fstSeq[ind1] != subseq[i]) {
            result += fstSeq[ind1];
            ind1++;
        }
        ind1++;
        while(sndSeq[ind2] != subseq[i]) {
            result += sndSeq[ind2];
            ind2++;
        }
        ind2++;
        result += subseq[i];
    }

    return result;
}

int main() {
    std::string fstSeq, sndSeq,result;
    int numTest = 0;

    while(true) {
        std::cin >> fstSeq;
        if(fstSeq == "#") break;

        std::cin >> sndSeq;

        result = shortestSuperSeq(fstSeq, sndSeq);

        std::cout << "Teste " << ++numTest << "\n" << result << "\n\n";
    }

    return 0;
}
