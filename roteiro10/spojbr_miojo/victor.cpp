#include <iostream>
#include <algorithm>

// i * j === k mod m
int find_i(int j, int k, int m){
    int i = 0;
    while (i * j % m != k){
        i++;
    }
    return i;
}

int main(){
    int time, hg1, hg2;
    std::cin >> time >> hg1 >> hg2;

    int hg1_time = hg1 * find_i(hg1, time, hg2);
    int hg2_time = hg2 * find_i(hg2, time, hg1);
    std::cout << std::min(hg1_time, hg2_time);

    return 0;
}
