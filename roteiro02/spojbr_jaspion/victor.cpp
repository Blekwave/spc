// A solução consiste de duas etapas. A primeira lê as palavras em japonês e a
// tradução para o português e guarda essa relação em um Map. A segunda parte
// do programa lê cada verso da letra e itera pelas palavras do verso. Cada pa-
// lavra é checada contra o dicionário. Se ela existe no dicionário, sua tradu-
// ção é impressa, caso contrário a palavra em si é impressa.

#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main(){
    int instances;
    std::cin >> instances;
    while (instances--){
        int num_entries, num_sentences;
        std::cin >> num_entries >> num_sentences;

        // Munches any remaining whitespace before reading with getline in the
        // loops below.
        std::cin.ignore(123, '\n');

        std::map<std::string, std::string> dict;
        for (int i = 0; i < num_entries; i++){
            std::string key, value;
            std::getline(std::cin, key);
            std::getline(std::cin, value);
            dict[key] = value;
        }

        for (int i = 0; i < num_sentences; i++){
            std::string sentence, word;
            std::getline(std::cin, sentence);
            std::stringstream s(sentence);
            bool first_word = true;
            while (s >> word){
                if (!first_word){
                    std::cout << " ";
                }
                if (dict.find(word) != dict.end()){
                    std::cout << dict[word];
                } else {
                    std::cout << word;
                }
                first_word = false;
            }
            std::cout << "\n";
        }

        // Imprima uma linha em branco no final de cada tradução.
        std::cout << "\n";
    }
    return 0;
}
