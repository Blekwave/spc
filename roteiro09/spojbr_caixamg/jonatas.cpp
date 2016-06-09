// A solução desse problema toma as dimensões A e B do retângulo e a função que determina o volume da caixa que é 
// (A-2x)*(B-2x)*x = 4x^3 - 2x^2*(A+B) + x*(A*B). Tendo essa função, para obtermos o volume máximo, simplesmente 
// tomamos a função de volume e derivamos uma vez, obtendo 12*x^2 - 4x*(A+B) + AB, e igualamos a 0. 
// Dessa forma, temos dois valores e, aplicando à fórmula do volume, o que apresenta o maior resultado é 
// impresso na console.

#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

void find_solutions(int A, int B);
double testValue(int A, int B, double x);

int main()  {

	int A, B;

	while(true)  {
		std::cin >> A >> B;
		if(A == 0 && B == 0)
			break;
		find_solutions(A, B);
	}

	return 0;
}

void find_solutions(int A, int B)  {

	double discriminant,
		   x1, x2,
		   first_solution, second_solution;

	discriminant = pow(-4*A -4*B, 2) - 4*12*A*B;
	x1 = (4*A + 4*B + sqrt(discriminant))/24;
	x2 = (4*A + 4*B - sqrt(discriminant))/24;

	first_solution = testValue(A, B, x1);
	second_solution = testValue(A, B, x2);

	std::cout << std::fixed;

	if(first_solution >= second_solution)
		std::cout << std::setprecision(4) << x1 << " " << std::setprecision(4) << first_solution << "\n";
	else
		std::cout << std::setprecision(4) << x2 << " " << std::setprecision(4) << second_solution << "\n";
}

double testValue(int A, int B, double x)  {

	return 4*(pow(x, 3)) - 2*(pow(x, 2))*(A + B) + x*A*B;
}
