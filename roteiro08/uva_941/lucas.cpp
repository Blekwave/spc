/*

Recebemos a string e a permutação desejada. A string é ordenada e a função de
geração da permutação calcula qual o caractere correto para cada posição. Para
uma dada posição, escolhemos o n-ésimo caractere da string ordenada e o removemos,
sendo que n é igual à permutação escolhida divida pela quantidade de permutações
possíveis para o restante da string. Para definir o restante dos caracteres, usamos
o mesmo método para o restante da string, escolhendo a permutação igual ao módulo da
permutação anterior pela quantidade de permutações possíveis nesse restante.

*/

#include <algorithm>
#include <iostream>
#include <vector>

std::string generateString(std::string, int, long long int);
long long int factorial(long long int);

int main() {

	int quant;
	long long int N;
	std::string S;

	std::cin >> quant;

	while(quant--) {
		std::cin >> S >> N;
		std::sort(S.begin(), S.end());
		std::cout << generateString(S, S.size(), N) << "\n";
	}

	return 0;
}

std::string generateString(std::string S, int size, long long int N) {
	if(!size) return "";

	long long int pos = N / (factorial(size - 1));
	N = N % factorial(size - 1);

	char letter = S[pos];
	S.erase(S.begin() + pos);

	return letter + generateString(S, size - 1, N);
}

long long int factorial(long long int N) {
	long long int res = 1;
	for(long long int i = 2; i <= N; i++) res *= i;
	return res;
}
