// O problema pode ser modelado em grafos da seguinte maneira: cada célula da
// matriz correspondente ao pasto é um vértice. Existe um arco de um vértice u
// a todo vértice v que pode ser alcançado movendo em linha reta a partir dele,
// sem passar por obstáculos. Não existem arcos de/para obstáculos.
// Com essa modelagem, computar o número de espelhos envolve descobrir o número
// de "curvas" a ser realizadas. Isso corresponde a encontrar o caminho mínimo
// de uma vaca à outra e subtrair 1 (um caminho com apenas uma aresta não tem
// curvas).

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using std::vector;
using std::cin;
using std::cout;
using std::queue;

typedef vector<vector<char>> PastureMatrix;

PastureMatrix readPasture(){
    int w, h;
    cin >> w >> h;
    PastureMatrix p;
    for (int i = 0; i < h; i++){
        vector<char> row;
        cin.ignore(1);
        for (int j = 0; j < w; j++){
            char c = cin.get();
            row.push_back(c);
        }
        p.push_back(row);
    }
    cin.ignore(3000);
    return p;
}

struct PastureGraph {
    vector<vector<int>> v;
    vector<char> vertex_type;
    int vertices;
    int w;
    int h;

    void addOutgoingArcs(int from){
        int i = from / w;
        int j = from % w;
        // add arcs leftward
        for (int col = j - 1; col >= 0; col--){
            int to = i * w + col;
            if (vertex_type[to] == '*'){
                break;
            }
            v[from].push_back(to);
        }
        // add arcs downward
        for (int row = i + 1; row < h; row++){
            int to = row * w + j;
            if (vertex_type[to] == '*'){
                break;
            }
            v[from].push_back(to);
        }
        // add arcs upward
        for (int row = i - 1; row >= 0; row--){
            int to = row * w + j;
            if (vertex_type[to] == '*'){
                break;
            }
            v[from].push_back(to);
        }
        // add arcs rightward
        for (int col = j + 1; col < w; col++){
            int to = i * w + col;
            if (vertex_type[to] == '*'){
                break;
            }
            v[from].push_back(to);
        }
    }

    PastureGraph(PastureMatrix m) {
        h = m.size();
        w = m[0].size();
        vertices = w * h;

        // Initialize m x n vertices
        for (auto row : m){
            for (auto c : row){
                vector<int> row;
                v.push_back(row);
                vertex_type.push_back(c);
            }
        }

        for (int i = 0; i < vertices; i++){
            if (vertex_type[i] != '*'){
                addOutgoingArcs(i);
            }
        }
    }

};

void findCows(PastureGraph g, int &starting_cow, int &end_cow){
    int i = 0;
    while (g.vertex_type[i] != 'C'){
        i++;
    }
    starting_cow = i;
    i++;
    while (g.vertex_type[i] != 'C'){
        i++;
    }
    end_cow = i;
}


int distanceBetweenCows(PastureGraph g, int starting_cow, int end_cow){
    vector<bool> visited(g.vertices, false);
    vector<int> distance(g.vertices, g.vertices * 3); // Impossibly large
    distance[starting_cow] = -1;
    visited[starting_cow] = true;

    queue<int> q;
    q.push(starting_cow);

    while (!q.empty()){
        int current = q.front();
        q.pop();

        if (current == end_cow){
            return distance[current];
        }

        for (int neighbor : g.v[current]){
            if (not visited[neighbor]){
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }
    return -1;
}



int main(){
    PastureMatrix p = readPasture();
    PastureGraph g(p);

    int start, end;
    findCows(g, start, end);
    int result = distanceBetweenCows(g, start, end);

    cout << result << "\n";

    return 0;
}
