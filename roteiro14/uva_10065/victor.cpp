// O problema consiste em encontrar, primeiramente, a casca convexa para o
// polígono de entrada. Depois disso, é preciso simplesmente retornar a pro-
// porção entre área não utilizada e a área da casca.
// Para obter a casca convexa, foi utilizado o algoritmo de Gift Wrapping.
// Esse algoritmo parte de um ponto que sempre faz parte da casca convexa
// (no caso, o ponto mais à esquerda do plano) e, então, itera por todos
// os pontos repetidamente, em busca do ponto que faz o vetor com ângulo
// mais anti-horário com o ponto de referência da casca. O algoritmo re-
// pete o procedimento até encontrar o ponto inicial novamente (dar a
// volta completa).

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

struct Point {
    int x;
    int y;

    friend bool operator==(const Point& l, const Point& r){
        return l.x == r.x and l.y == r.y;
    }

    friend bool operator!=(const Point& l, const Point& r){
        return not (l == r);
    }
};

Point leftmostPoint(vector<Point> &points){
    Point leftmost = {1001, 0};
    for (Point p : points){
        if (p.x < leftmost.x){
            leftmost = p;
        }
    }
    return leftmost;
}

bool counterClockwise(Point &origin, Point &ref, Point &op){
    int ref_x = ref.x - origin.x, ref_y = ref.y - origin.y;
    int op_x = op.x - origin.x, op_y = op.y - origin.y;
    return (ref_x * op_y - op_x * ref_y) > 0;
}

vector<Point> convexHull(vector<Point> &points){
    Point hullCorner = leftmostPoint(points);
    vector<Point> hull;

    do {
        hull.push_back(hullCorner);
        Point candidate = points.front();
        for (Point p : points){
            if (candidate == hullCorner or
                    counterClockwise(hullCorner, candidate, p)){
                candidate = p;
            }
        }
        hullCorner = candidate;
    } while (hullCorner != hull.front());

    return hull;
}

double abs(double d){
    return d < 0 ? -d : d;
}

double polygonArea(vector<Point> &points){
    double area = 0;
    for (auto it = points.begin(); it != points.end() - 1; it++){
        auto next = it + 1;
        area += it->x * next->y - it->y * next->x;
    }
    Point first = points.front(), last = points.back();
    area += last.x * first.y - last.y * first.x;
    return abs(area / 2);
}


double convexHullArea(vector<Point> &points){
    vector<Point> convex_hull = convexHull(points);
    return polygonArea(convex_hull);
}

double runTest(int n){
    vector<Point> points;
    for (int i = 0; i < n; i++){
        Point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    double tile_area = polygonArea(points);
    double container_area = convexHullArea(points);
    return tile_area / container_area;
}

int main(){
    int n;
    int count = 1;
    while (true){
        cin >> n;
        if (n == 0){
            break;
        }
        double percentage = runTest(n);
        cout << "Tile #" << count << "\nWasted Space = "
             << fixed << setprecision(2) << (1 - percentage) * 100 << " %\n\n";
        count++;
    }
    return 0;
}
