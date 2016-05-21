/*

As operações com números racionais podem ser feitas utilizando as regras já conhecidas
para isso. Para simplificar o resultado, basta descobrir o mdc entre numerador e 
denominador e dividí-los por esse mdc.

*/

#include <iostream>

void simplify(int, int, int&, int&);
int gcd(int, int);

int main() {
	int N, a, b, c, d, num, den, snum, sden;
	char op, aux;

	std::cin >> N;
	while(N--) {
		std::cin >> a >> aux >> b >> op >> c >> aux >> d;

		switch(op) {
			case '+':
				den = b * d;
				num = (a * den / b) + (c * den / d);
				break;
			case '-':
				den = b * d;
				num = (a * den / b) - (c * den / d);
				break;
			case '*':
				num = a * c;
				den = b * d;
				break;
			case '/':
				num = a * d;
				den = b * c;
				break;
		}

		simplify(num, den, snum, sden);

		std::cout << num << "/" << den << " = " << snum << "/" << sden << "\n";

	}

	return 0;
}

void simplify(int num, int den, int& snum, int& sden) {
	int x = gcd(num, den);

	snum = num / x;
	sden = den / x;

	if(sden < 0) {
		snum *= -1;
		sden *= -1;
	}
}

int gcd(int a, int b) {
	int aux;

	while(b) {
		aux = b;
		b = a % b;
		a = aux;
	}

	return a;
}
