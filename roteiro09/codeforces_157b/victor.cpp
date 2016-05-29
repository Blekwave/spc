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
