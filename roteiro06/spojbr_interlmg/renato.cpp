/**
 * Esse problema foi resolvido utilizando o algoritmo de Prim para montar uma
 * árvore geradora mínima.
 * Uma min-heap foi utilizada como a estrutura de dados do algoritmo de Prim.
 * Para calcular o mínimo tamanho da rede necessário, durante a execução do
 * algoritmo de Prim, assim que se remove um elemento da Heap (que é um
 * vértice com o peso calculado pelo algoritmo), se testa esse elemento ao
 * maior peso visto anteriormente. Caso o peso for maior, esse peso é salvo.
 * Desse modo, ao final da execução do algoritmo, o valor salvo é o maior peso
 * da árvore geradora mínima, que é a menor distância para que todas as cidades
 * estejam conectadas.
 */

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>

template<class T, class Compare = std::less<T>, class Container = std::vector<T>>
class Heap {
    Container _c;
    Compare _comp;

public:
    Heap() { }

    inline void push(const T &t) {
        _c.push_back(t);
        std::push_heap(_c.begin(), _c.end(), _comp);
    }

    inline void pop() {
        std::pop_heap(_c.begin(), _c.end(), _comp);
        _c.pop_back();
    }

    inline T &top() {
        return _c.front();
    }

    /// pops & returns copy.
    inline T pop_copy() {
        T t = top();
        pop();
        return t;
    }

    inline const T &at(size_t i) {
        return _c[i];
    }

    inline size_t size() {
        return _c.size();
    }

    inline bool empty() {
         return _c.empty();
    }

    /// Change to the direction of the parent (only in this direction).
    void update(size_t i, std::function<void(T&)> f) {
        f(_c[i]);

        size_t p = (i-1)/2;
        while(i && _comp(_c[p], _c[i])) {
            std::swap(_c[p], _c[i]);
            i = p;
            p = (i-1)/2;
        }
    }
};

struct City {
    double x, y, value;

    City(double _x, double _y, double _value = DBL_MAX)
        : x(_x), y(_y), value(_value) {  }

    void print() {
        std::cout << value;
    }

    inline static double dist(const City &a, const City &b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }
};

bool operator>(const City &a, const City &b) {
    return a.value > b.value;
}

typedef Heap<City, std::greater<City>> MinHeap;

double prim(MinHeap &cities) {
    double maxSize = 0.0;
    cities.update(0, [=] (City &c) {
        c.value = 0.0;
    });

    while(!cities.empty()) {
        auto t = cities.pop_copy();
        if(maxSize < t.value)
            maxSize = t.value;

        for(size_t i = 0; i < cities.size(); ++i) {
            auto d = City::dist(t, cities.at(i));

            if(d < cities.at(i).value)
                cities.update(i, [=] (City &c) {
                    c.value = d;
                });
        }
    }

    return maxSize;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    for(;;) {
        size_t n;
        std::cin >> n;
        if(!n)
            break;

        MinHeap cities;
        while(n--) {
            double x, y;
            std::cin >> x >> y;
            cities.push(City(x, y));
        }

        std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(4)
            << prim(cities) << "\n";
    }

    return 0;
}
