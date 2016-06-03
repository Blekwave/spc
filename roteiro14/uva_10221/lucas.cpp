/*

Para calcular a distância de arco entre os satélites basta multiplicar o raio da
órbita (s + raio da terra) e o ângulo entre eles em radianos. Para o cálculo da
distância de corda, utilizamos um pouco de trigonometria: se dividirmos o triângulo
formado pelos dois satélites e o centro da Terra em dois utilizando sua bissetriz
em relação ao ângulo dado, teremos dois triângulos retângulos. Calculamos o
seno da metade do ângulo dado e multiplicamos pelo raio da órbita, e isso nos dará
metade de distância de corda entre os satélites. Basta agora multiplicar o
resultado por 2.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

const int EARTH_RADIUS = 6440;

double degToRad(double degrees);
double arcDist(double height, double angle);
double chordDist(double height, double angle);

int main() {
	double s, a;
	std::string unit;

	while(std::cin >> s >> a >> unit) {
		if(unit == "min") a /= 60.0;

		std::cout << std::fixed << std::setprecision(6)
		          << arcDist(s, a) << " "
		          << chordDist(s, a) << "\n";
	}

	return 0;
}

double degToRad(double degrees) {
	// convert degrees to smallest value in radians
	degrees = fmod(degrees, 360);
	if(degrees > 180) degrees = 360 - degrees;

	return 2.0 * M_PI * degrees / 360.0;
}

double arcDist(double height, double angle) {
	return (height + EARTH_RADIUS) * degToRad(angle);
}

double chordDist(double height, double angle) {
	return std::abs(2.0 * sin(degToRad(angle / 2.0)) * (height + EARTH_RADIUS));
}
