/*

A solução do problema é bastante simples: lemos a posição do cachorro e do roedor,
e para cada buraco recebido, calculamos a distância de ambos até o buraco. Caso a
distância do roedor ao buraco seja menor que metade da distância do cachorro até o
buraco (dado que ele corre com o dobro da velocidade), encontramos uma saída possível
e exibimos na tela.

*/

#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>

typedef std::pair<float,float> position;

float distance(position a, position b) {
	float x, y;
	x = a.first  - b.first;
	y = a.second - b.second;
	return sqrt(x*x + y*y);
}

int main() {
	int N;

	while(std::cin >> N) {
		position gopher, dog, hole;
		position bestSoFar;
		bestSoFar.first = 10001;

		std::cin >> gopher.first >> gopher.second >> dog.first >> dog.second;

		while(N--) {
			std::cin >> hole.first >> hole.second;
			if(bestSoFar.first == 10001 && distance(gopher, hole) <= distance(dog, hole) / 2) {
				bestSoFar.first = hole.first;
				bestSoFar.second = hole.second;
			}
		}

		if(bestSoFar.first == 10001) {
			std::cout << "The gopher cannot escape.\n";
		} else {
			bestSoFar.first  = round(bestSoFar.first  * 1000)/1000;
			bestSoFar.second = round(bestSoFar.second * 1000)/1000;
			std::cout << std::fixed << std::setprecision(3)
			          << "The gopher can escape through the hole at ("
			          << bestSoFar.first << "," << bestSoFar.second << ").\n";
		}
	}

	return 0;
}
