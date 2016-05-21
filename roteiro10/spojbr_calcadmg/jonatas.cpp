#include <algorithm>
#include <iostream>

long int gcd(long int firstNumber, long int secondNumber);

int main()   {
	
	int T;
	long int A, B, C, D,
			 K = 0;

	std::cin >> T;

	while(T--)  {

		std::cin >> A >> B >> C >> D;
		
		//Guarantees that the first number is bigger than the second
		if(std::abs(C - A) < std::abs(D - B))
			K = gcd(std::abs(D - B), std::abs(C - A));
		else
			K = gcd(std::abs(C - A), std::abs(D - B));

		std::cout << K+1 << "\n";

	}

	return 0;
}

long int gcd(long int firstNumber, long int secondNumber)  {

	if(secondNumber == 0)  
		return firstNumber;
	else
		return gcd(secondNumber, firstNumber % secondNumber);

}