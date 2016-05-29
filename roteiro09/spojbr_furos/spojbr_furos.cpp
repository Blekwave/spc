#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

void find_shortest_distance(std::vector <std::pair <int,int> > points);
double calc_dist(std::pair<int,int> p1, std::pair<int,int> p2);

int main()  {

	int N,
		x, y,
		test_counter = 1;
	std::vector <std::pair <int,int> > points;

	while(true)  {

		std::cin >> N;
		if(N == 0)
			break;

		while(N--)  {

			std::cin >> x >> y;
			points.push_back(std::make_pair(x, y)); 
		}

		std::cout << "Teste " << test_counter << "\n";
		find_shortest_distance(points);
		points.erase(points.begin(), points.end());
		test_counter++;
	}

	return 0;
}

void find_shortest_distance(std::vector <std::pair <int,int> > points)  {
	std::vector<double> distances;
	double higher_distance = 0,
		current_distance = 0;
	int higher_diameter = 0;

	for(int i = 0; i < points.size(); i++)  {
		
		for(int j = 0; j < points.size(); j++)  {
			if(j != i)  {
				current_distance = calc_dist(points[i], points[j]);
				
				if(current_distance > higher_distance)
					higher_distance = current_distance;
			}
		}

		distances.push_back(higher_distance);
		higher_distance = 0;
	}

	std::sort(distances.begin(), distances.end());
	higher_diameter = ceil(2 * distances[0] + 5);
	std::cout << higher_diameter << "\n\n";
}

double calc_dist(std::pair<int,int> p1, std::pair<int,int> p2)  {

	if(p1.first == p2.first)
		return std::abs(p1.second - p2.second);
	else {
		if(p1.second == p2.second)
			return std::abs(p1.first - p2.first);
		else  {
			return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
		}
	}
}
