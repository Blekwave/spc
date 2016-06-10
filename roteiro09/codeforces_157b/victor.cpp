// O problema consiste em encontrar a área da pintura na parede que está pintada
// de vermelho. Essencialmente, basta, partindo do círculo mais externo, que é
// vermelho (visto que o problema informa que a pintura externa aos círculos
// é azul), somar e subtrair as áreas dos círculos alternadamente.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>

#define M_PI 3.14159265358979323846

int main(){
    int n;
    std::cin >> n;
    std::vector<int> radii;
    for (int i = 0; i < n; i++){
        int r;
        std::cin >> r;
        radii.push_back(r);
    }

    std::sort(radii.begin(), radii.end(), std::greater<int>());

    double red_area = 0;
    double mult = 1;
    for (int r : radii){
        red_area += mult * M_PI * r * r;
        mult *= -1;
    }
    std::cout << std::setprecision(10) << red_area;
    return 0;
}
