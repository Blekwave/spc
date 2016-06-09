// A solução desse problema percorre os caracteres da string da entrada e insere e um map e, no caso do
// caractere já estar no map, o indice dele no map é incrementado. Após isso, o algoritmo percorre cada
// posição do map e incrementa o contador do número de pares ordenados existentes com o valor da posição
// do map ao quadrado. Depois de percorrer o map, o programa imprime o valor encontrado na console.


#include <iostream>
#include <string>
#include <map>

int main()  {
	std::string inputString;
	long long int numberOfPairs = 0;
	std::map<char,long long int> charMap;
	std::getline(std::cin, inputString);
	
	for(int i = 0; i < inputString.size(); i++)  {
		charMap[inputString[i]]++;
	}

	for(auto q : charMap) {
		numberOfPairs += q.second * q.second;
	} 

	std::cout << numberOfPairs;

	return 0;
}
