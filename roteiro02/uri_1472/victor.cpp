// Dada a circunferência, é sabido que, para que possa haver um triângulo equi-
// látero formado por vértices situados na mesma, é necessário que a distância
// entre vértices adjacentes seja de circunferência/3.
// Portanto, após calcular o valor da circunferência total, o programa itera
// pelos vértices e verifica se há vértices nas posições v + c/3 e v + 2c/3,
// sendo v a posição do vértice inicial e c o valor da circunferência. Se isso
// ocorre, um triângulo pode ser formado.
// É importante cautela para evitar que o mesmo triângulo seja contado mais de
// uma vez.

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
