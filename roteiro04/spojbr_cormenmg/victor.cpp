// O problema consiste em encontrar as subsequências contíguas não-sobrepostas
// que somam 42. Para isso, a solução proposta cria um vetor de inteiros e
// define o início da seção desse vetor com valores que podem dar início a uma
// subsequência com valor 42 como a posição inicial. Sempre que um valor é
// lido, é somado esse valor a todos os itens do vetor a partir do início da
// seção e o valor em si é concatenado ao fim ao vetor. Se algum desses valores
// resultou em um valor igual a 42, é somado 1 ao contador de subsequências, e
// o início da seção é redefinido como a posição após o valor lido. Se houve um
// valor na seção maior que 42, o início da seção é redefinido para a posição
// após esse valor.

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

const int adams_number = 42;

int countAdamsWords(){
    int letter_count;
    cin >> letter_count;

    vector<int> counts;

    int begin = 0;
    int adams_count = 0;

    for (int i = 0; i < letter_count; i++){
        int letter;
        cin >> letter;

        for (int j = begin; j < i; j++){
            counts[j] += letter;
            if (counts[j] == adams_number){
                adams_count++;
                begin = i + 1;
                break;
            }
            if (counts[j] >= adams_number){
                begin = j + 1;
            }
        }

        counts.push_back(letter);
    }

    return adams_count;
}

int main(){
    int sections;
    cin >> sections;

    while (sections--){
        int res = countAdamsWords();
        cout << res << "\n";
    }

    return 0;
}
