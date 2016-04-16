#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>

const int MAX_LETTERS = 60;

void sortWords(std::string palavra, long long int sumCombinations, int wordCounter);

int main()  {
	std::string palavra;
	long long int sumCombinations = 0;
	int wordCounter = 1;

	while(std::getline (std::cin, palavra))  {
		if(std::cin.eof())
			break;
		sortWords(palavra, sumCombinations, wordCounter);
		wordCounter++;
	}
	return 0;
}

void sortWords(std::string palavra, long long int sumCombinations, int wordCounter)  {
	std::vector<int> combinations;
	for(int i = 0; i < palavra.size(); i++)  {
		if(palavra[i] == 'b')
			combinations.push_back(i + 1);
	}
	if(combinations.size() > 0)  {
		for(int i = 0; i < combinations.size(); i++)  {
			long long int exponent = palavra.size() - combinations[i];
			sumCombinations += pow(2, exponent);
		}
	}
	std::cout << "Palavra " << wordCounter << "\n" << sumCombinations << "\n\n";

}
