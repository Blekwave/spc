#include <algorithm>
#include <iostream>
#include <string>
#include <cmath> 

void readInput(int &current_degree, double &x, double &y);

int main()  {

	int n_cases,
		n_directions;

	std::cin >> n_cases;

	while(n_cases--)  {

		std::cin >> n_directions;
		
		int current_degree = 0;
		std::pair<double,double> position (0.0,0.0);

		while(n_directions--)  {
			readInput(current_degree, position.first, position.second);
		}

		std::cout << (int) round(sqrt((position.first * position.first) + (position.second * position.second)));
		std::cout << std::endl;
	}

	return 0;
}

void readInput(int &current_degree, double &x, double &y)  {

	int value;
	std::string direction;

	std::cin >> direction >> value;
	
	double degree = current_degree * M_PI / 180.0;

	switch(direction[0])  {
		case 'f':
			x += value * cos(degree);
			y += value * sin(degree);
			break;
		case 'b':
			x -= value * cos(degree);
			y -= value * sin(degree);
			break;
		case 'l':
			current_degree = (current_degree + value + 360) % 360;
			break;
		case 'r':
			current_degree = (current_degree - value + 360) % 360;
			break;
	}
}
