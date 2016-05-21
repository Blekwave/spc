/*

A quantidade Q de fatias na qual podemos dividir uma pizza com N cortes é dada
pela seguinte fórmula de recorrência: Q(N) = Q(N - 1) + N; Q(0) = 1. Essa
fórmula pode ser vista obviamente como a soma dos valores de 1 até N mais 1.
Usando a fórmula de soma de uma progressão aritmética, temos a fórmula direta
1 + (N + 1) * N/2.

*/

#include <iostream>

int main() {
	long long int N;

	while(true) {
		std::cin >> N;
		if(N < 0) break;

		std::cout << 1 + ((N + 1) * N/2) << "\n";
	}

	return 0;
}
