// A solução desse problema simplesmente verifica se a coordenada dos pontos dados estão dentro dos limites dados. Se a coordenada
// x do ponto for maior ou igual à coordenada x do canto superior e menor ou igual à coordenada x do canto inferior, além da
// coordendada y do ponto ser maior ou igual à coordenada y do canto inferior e menor ou igual à coordenada y do canto superior,
// tem-se um ponto válido. Incrementa-se um contador de meteoritos para cada ponto válido e imprime-se esse contador na console ao
// terminar de analisar todos os pontos dados.

#include <algorithm>
#include <iostream>

void verificaPonto(std::pair<int,int> cantoSuperior, std::pair<int,int> cantoInferior, int x, int y, int &n_meteoritos);

int main()  {

	std::pair<int,int> cantoSuperior;
	std::pair<int,int> cantoInferior;
	int N,
		x, y,
		n_meteoritos,
		n_teste = 1;

	while(true)  {

		std::cin >> cantoSuperior.first >> cantoSuperior.second;
		std::cin >> cantoInferior.first >> cantoInferior.second;

		if(cantoSuperior.first == 0 && cantoSuperior.second == 0 && cantoInferior.first == 0 && cantoInferior.second == 0)
			break;

		std::cin >> N;
		
		n_meteoritos = 0;

		while(N--)  {

			std::cin >> x >> y;
			verificaPonto(cantoSuperior, cantoInferior, x, y, n_meteoritos);
		}

		std::cout << "Teste " << n_teste << std::endl << n_meteoritos << std::endl << std::endl;
		n_teste++;
	} 

	return 0;
}

void verificaPonto(std::pair<int,int> cantoSuperior, std::pair<int,int> cantoInferior, int x, int y, int &n_meteoritos)  {

	if(x >= cantoSuperior.first && x <= cantoInferior.first)  {
		if(y >= cantoInferior.second && y <= cantoSuperior.second)  {
			n_meteoritos++;
		}
	}
}