/*
 * Esse problema foi resolvido utilizando o produto misto. Dado os pontos a,
 * b, c e d, podemos definir os vetores ba (b - a), ca (c - a) e da (d - a).
 * Com isso, o produto misto, que é o volume do paralelepípedo dado pelos 3
 * vetores, é fabs((ba cross ca) dot da). Dividindo isso por 6 encontramos o
 * volume do tetraedro triangular.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

struct Vector {
    double x, y, z;
    Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {  }
};

double operator*(const Vector &l, const Vector &r) {
    return l.x * r.x + l.y * r.y + l.z * r.z;
}

Vector operator%(const Vector &l, const Vector &r) {
    return Vector(
        l.y * r.z - l.z * r.y,
        l.z * r.x - l.x * r.z,
        l.x * r.y - l.y * r.x
    );
}

struct Point {
    double x, y, z;
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {  }
    static Point fromStdin() {
        double x, y, z;
        std::cin >> x >> y >> z;
        return Point(x, y, z);
    }
};

Vector operator-(const Point &l, const Point &r) {
    return Vector(l.x - r.x, l.y - r.y, l.z - r.z);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(6);
    int n;

    std::cin >> n;
    while(n--) {
        Point a = Point::fromStdin(),
              b = Point::fromStdin(),
              c = Point::fromStdin(),
              d = Point::fromStdin();

        Vector ba = b - a,
               ca = c - a,
               da = d - a;

        std::cout << fabs((ba % ca) * da) / 6.0 << '\n';
    }

    return 0;
}
