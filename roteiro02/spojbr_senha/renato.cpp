#include <iostream>
#include <map>
#include <cstring>

typedef std::pair<int, int> intPair;
typedef std::map<char, intPair> letrasMap;
typedef std::pair<char, intPair> letrasPair;

int main() {
    int senhas[6][10];
    int n;
    int teste = 0;
    char currChar;
    letrasMap letras;

    letras.insert(letrasPair('A', intPair(0, 0)));
    letras.insert(letrasPair('B', intPair(0, 0)));
    letras.insert(letrasPair('C', intPair(0, 0)));
    letras.insert(letrasPair('D', intPair(0, 0)));
    letras.insert(letrasPair('E', intPair(0, 0)));

    for(;;) {
        std::cin >> n;
        if(!n)
            break;

        std::memset(senhas, 1, 6 * 10 * sizeof(int));
        for(int i = 0; i < n; ++i) {
            std::cin >> letras['A'].first;
            std::cin >> letras['A'].second;
            std::cin >> letras['B'].first;
            std::cin >> letras['B'].second;
            std::cin >> letras['C'].first;
            std::cin >> letras['C'].second;
            std::cin >> letras['D'].first;
            std::cin >> letras['D'].second;
            std::cin >> letras['E'].first;
            std::cin >> letras['E'].second;

            for(int j = 0; j < 6; ++j) {
                std::cin >> currChar;

                for(int k = 0; k < 10; ++k) {
                    if(k != letras[currChar].first
                            && k != letras[currChar].second) {
                        senhas[j][k] = 0;
                    }
                }
            }
        }

        std::cout << "Teste " << ++teste << "\n";
        for(int i = 0; i < 6; ++i) {
            int j;
            for(j = 0; j < 10; ++j)
                if(senhas[i][j])
                    break;

            if(i)
                std::cout << " ";
            std::cout << j;
        }
        std::cout << "\n";
    }

    return 0;
}
