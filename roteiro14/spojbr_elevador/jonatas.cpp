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