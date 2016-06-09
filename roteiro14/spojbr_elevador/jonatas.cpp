// A solução desse problema verifica primeiramente se a menor dimensão da caixa comporta a circunferência de maior diâmetro. Em caso negativo,
// imprime-se 'N'. No caso positivo, calculamos a maior distância possível entre os centros das circunferências, quando as elas são colocadas
// em extremidades diagonais, que é igual à √((L-R1-R2)^2 + (C-R1-R2)^2). Se esse valor for maior ou igual à soma dos dois raios R1 e R2, os
// cículos cabem na caixa e é impresso 'S'. Em caso contrário, imprime-se 'N'.

#include <algorithm>
#include <iostream>
#include <cmath>

void determine_if_fits(int L, int C, int R1, int R2);

int main()  {
	int L, C, R1, R2;

	while(true)  {

		std::cin >> L >> C >> R1 >> R2;
		
		if(L == 0 && C == 0 && R1 == 0 && R2 == 0) 
			break;

		determine_if_fits(L, C, R1, R2);
		std::cout << std::endl;

	}
	return 0;
}

void determine_if_fits(int L, int C, int R1, int R2)  {
	
	double R = R1 + R2,
		max_R;

	if(2*R1 > L || 2*R1 > C)  {
		std::cout << "N";
		return;
	}
	else if(2*R2 > L || 2*R2 > C)  {
		std::cout << "N";
		return;
	}

	max_R = sqrt(pow(L-R1-R2, 2) + pow(C-R1-R2, 2));

	if(max_R >= R)
		std::cout << "S";
	else
		std::cout << "N";
}