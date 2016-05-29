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