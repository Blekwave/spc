// A solução proposta itera por todas as combinações possíveis de diretores,
// em ordem crescente de tamanho da combinação. Para cada combinação, é feita
// a união do conjunto de chaves dos diretores combinados através de operações
// bit-a-bit. Caso a união tenha o número de chaves necessário, esse valor é
// impresso. Se nenhuma combinação consegue cumprir esse valor, é impossível
// abrir o cofre.

#include <iostream>
#include <vector>
#include <cstdint>

const int MAX_NUM_KEYS = 32;

typedef std::uint32_t KeySet;

int countBits(std::uint32_t ks){
    int count = 0;
    while (ks > 0){
        count += ks & 1;
        ks >>= 1;
    }
    return count;
}

std::vector<KeySet> readDirectors(int d){
    std::vector<KeySet> directors;
    for (int i = 0; i < d; i++){
        int num_keys;
        std::cin >> num_keys;
        KeySet director = 0;
        for (int j = 0; j < num_keys; j++){
            int key;
            std::cin >> key;
            director |= 1 << key;
        }
        directors.push_back(director);
    }
    return directors;
}

void runTestCase(){
    int m, d;
    std::cin >> m >> d;
    auto directors = readDirectors(d);
    int min_comb = d + 1;

    int last_comb = 1 << d;
    for (int comb = 0; comb < last_comb; comb++){
        KeySet key_union = 0;
        for (int i = 0, loop_comb = comb; loop_comb > 0; loop_comb >>= 1, i++){
            if (loop_comb & 1){
                key_union |= directors[i];
            }
        }
        int c = countBits(key_union);
        if (c >= m){
            int comb_size = countBits(comb);
            if (comb_size < min_comb){
                min_comb = comb_size;
            }
        }
    }

    if (min_comb == d + 1){
        std::cout << "Desastre!\n";
    } else {
        std::cout << min_comb << "\n";
    }
}

int main(int argc, char const* argv[]) {
    int cases;
    std::cin >> cases;
    while (cases--){
        runTestCase();
    }
    return 0;
}
