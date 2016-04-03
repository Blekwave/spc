#include <iostream>
#include <map>
#include <vector>

int main(){
    int num_points;
    while (std::cin >> num_points){
        std::vector<int> intervals;
        int circumference = 0;

        for (int i = 0; i < num_points; i++){
            int interval;
            std::cin >> interval;
            circumference += interval;
            intervals.push_back(interval);
        }

        if (circumference % 3 != 0){
            std::cout << 0 << "\n";
            continue;
        }

        int vertex_interval = circumference / 3;

        std::map<int, int> vertices;

        int current = 0;
        for (auto interval : intervals){
            int prev = current - vertex_interval;
            vertices[current] = vertices[prev] + 1;
            current += interval;
        }

        int triangles = 0;
        for (auto kvpair : vertices){
            if (kvpair.second == 3){
                triangles++;
            }
        }

        std::cout << triangles << "\n";
    }

    return 0;
}
