/*

Para cada caso de teste, recebemos a posição M, o número de segmentos e o início
do primeiro segmento. A partir daí, para cada novo ponto, descobrimos o ponto do
segmento determinado pelos últimos dois pontos dados que está mais próximo de M,
fazendo um vetor que vai de M até o ponto inicial do segmento e retirando desse
vetor a componente paralela à reta. Armazenamos o ponto dos segmentos que for mais
próximo de M, e temos assim o resultado.

*/

#include <iostream>
#include <iomanip>
#include <cmath>

class Vector {
	public:
	float x, y;

	Vector() {};

	Vector(float xn, float yn) {
		this->x = xn;
		this->y = yn;
	}

	void operator= (const Vector& op) {
	    this->x = op.x;
	    this->y = op.y;
	}

	Vector operator+(const Vector& op) {
	    return Vector(this->x + op.x, this->y + op.y);
	}

	Vector operator-(const Vector& op) {
	    return Vector(this->x - op.x, this->y - op.y);
	}

	Vector operator* (const float& x) {
	    return Vector(this->x * x, this->y * x);
	}

	Vector normalize(void) {
	    if(this->getLength() != 0) {
	        float len = this->getLength();
	        this->x /= len;
	        this->y /= len;
	    }
	    return *(this);
	}

	float dot(Vector op) {
	    return (this->x * op.x) + (this->y * op.y);
	}

	float getLength() {
	    return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}
};

Vector closestPoint(Vector lineStart, Vector lineSeg, Vector pt) {
	Vector lineDir = lineSeg;
	lineDir.normalize();
	
	Vector PQ      = lineStart - pt,
		   result  = pt + PQ - (lineDir * PQ.dot(lineDir));

	// if closest point in line is not in the segment, returns
	// one of the extremes of the segment
	if((result - lineStart).dot(lineDir) < 0) {
		// point is behind starting point
		result = lineStart;
	} else if((result - lineStart).dot(lineDir) > lineSeg.getLength()){
		// point is after the end point
		result = lineStart + lineSeg;
	}

	return result;
}

int main() {
	Vector M, begin, finish, closest;
	float N;

	while(std::cin >> M.x >> M.y >> N >> begin.x >> begin.y) {
		bool first = true;
		while(N--) {
			std::cin >> finish.x >> finish.y;

			// closest point from line to M
			Vector linePoint = closestPoint(begin, finish - begin, M);

			if((M - linePoint).getLength() < (M - closest).getLength() || first) {
				closest = linePoint;
				first = false;
			}

			begin.x = finish.x;
			begin.y = finish.y;
		}

		std::cout << std::fixed << std::setprecision(4)
		          << closest.x << "\n" << closest.y << "\n";
	}

	return 0;
}
