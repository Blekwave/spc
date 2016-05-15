/*

Para resolver o problema, basta passarmos por cada caractere da entrada e trocar
cada símbolo pelo número correspondente quando necessário. Para isso, medimos a
distância entre os caracteres e dependendo dela escolhemos qual número inserir.
Caso não seja adequado inserir um número na posição, apenas repetimos o caractere
lido (0, 1 ou -).

*/

#include <iostream>

void telephonify(std::string, std::string&);

int main() {
	std::string phrase;

	while(getline(std::cin, phrase)) {
		std::string result;
		telephonify(phrase, result);
		std::cout << result << "\n";
	}

	return 0;
}

void telephonify(std::string phrase, std::string& result) {
	for(char c : phrase) {
		if(c - 'A' < 0)       result.push_back(c);
		else if (c - 'A' < 3) result.push_back('2');
		else if (c - 'D' < 3) result.push_back('3');
		else if (c - 'G' < 3) result.push_back('4');
		else if (c - 'J' < 3) result.push_back('5');
		else if (c - 'M' < 3) result.push_back('6');
		else if (c - 'P' < 4) result.push_back('7');
		else if (c - 'T' < 3) result.push_back('8');
		else if (c - 'W' < 4) result.push_back('9');
		else				  result.push_back(c);
	}
}
