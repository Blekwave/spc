#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.141592653589793

void determineAreas(double a, double b, double c);

int main()  {

	double a, b, c;

	while(true)  {
		
		std::cin >> a >> b >> c;
		
		if(std::cin.eof())
			break;
		
		determineAreas(a, b, c);

	}
	return 0; 
}

void determineAreas(double a, double b, double c)  {
	
	long double s, A, r, R,
		   bigCircle, smallCircle;

	s = (a + b + c)/2;
	A = sqrt(s*(s-a)*(s-b)*(s-c));
	r = A/s;
	R = (a*b*c)/(4*A);

	bigCircle = PI * pow(R, 2);
	smallCircle = PI * pow(r, 2);

	std::cout << std::fixed;
	std::cout << std::setprecision(4) << bigCircle - A << " "
			  << std::setprecision(4) << A - smallCircle << " "
			  << std::setprecision(4) << smallCircle << "\n";

}