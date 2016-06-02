/*

Recebemos todos os pontos na cebola e utilizamos o algoritmo de Gift wrapping
(também conhecido como Jarvis march) para obter a casca convexa da cebola. Assim,
obtemos a primeira camada. Removemos os pontos que estão nessa casca e repetimos
o processo até que restem apenas pontos colineares na cebola, já que pontos
colineares não podem formar um polígono de mais de dois lados. Ao fim de todo
esse processo, teremos retirado todas as cascas, e no processo contado quantas
cascas existem.

*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

class Vector {
	public:
	int x, y;

	Vector() {};

	Vector(int xn, int yn) {
		this->x = xn;
		this->y = yn;
	}

	Vector operator-(const Vector& op) {
	    return Vector(this->x - op.x, this->y - op.y);
	}

	void operator= (const Vector& op) {
	    this->x = op.x;
	    this->y = op.y;
	}

	bool operator== (const Vector& op) {
	    return this->x == op.x && this->y == op.y;
	}

	bool operator!= (const Vector& op) {
		return this->x != op.x || this->y != op.y;
	}

	int cross(Vector op) {
	    return (this->x * op.y) - (this->y * op.x);
	}

	double getLength() {
	    return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}
};

int convexHullCount(std::vector<Vector>& points) {
	int count = 0;

	while(points.size() > 2) {
		// Finds leftmost point
		int next = 0;
		for(int i = 1; i < points.size(); i++) {
			if(points[i].x < points[next].x ||
			   points[i].x == points[next].x && points[i].y < points[next].y) {
				next = i;
			}
		}


		std::vector<int> pointsInHull;
		bool colinear = true;
		do {
			pointsInHull.push_back(next);

			int nextCandidate = pointsInHull.back() == 0 ? 1 : 0;
			for(int i = 0; i < points.size(); i++) {
				if(i == pointsInHull.back()) continue;
				Vector P = points[pointsInHull.back()],
				       X = points[i];

				Vector vNextCandidate = points[nextCandidate];
				int cProd = (X - P).cross(vNextCandidate - P);
				if(cProd < 0) {
					nextCandidate = i;
					colinear = false;
				} else if(cProd == 0 && X.getLength() < vNextCandidate.getLength() &&
					      std::find(pointsInHull.begin(), pointsInHull.end(), i) == pointsInHull.end()) {
					nextCandidate = i;
				}
			}

			next = nextCandidate;
		} while(next != pointsInHull[0]);

		std::sort(pointsInHull.begin(), pointsInHull.end());

		for(int i = pointsInHull.size() - 1; i >= 0; i--) {
			points.erase(points.begin() + pointsInHull[i]);
		}

		if(!colinear) count++;
	}

	return count;
}

int main() {
	int N, x, y;

	while(true) {
		std::cin >> N;
		if(!N) break;

		std::vector<Vector> points;
		while(N--) {
			std::cin >> x >> y;
			points.push_back(Vector(x, y));
		}

		if(convexHullCount(points) % 2 == 1) {
			std::cout << "Take this onion to the lab!\n";
		} else {
			std::cout << "Do not take this onion to the lab!\n";
		}

	}

	return 0;
}
