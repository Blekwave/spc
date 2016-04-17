#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::cin;
using std::cout;
using std::pair;

// d == 0 -> horizontal
// d == 1 -> vertical

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

struct Arc {
    int to;
    int value;
    Arc (int to, int value) : to(to), value(value) {};
};

struct PastureGraph {
    vector<vector<Arc>> v;
    vector<char> vertex_type;
    int vertices;
    int w;
    int h;

    void addArc(int from, int i, int j, int d, int value){
        int to = (i * w + j) * 2 + d;
        if (vertex_type[to] != '*'){
            Arc a(to, value);
            v[from].push_back(a);
        }
    }

    void addOutgoingArcs(int from){
        int d = from % 2;
        int i = from / 2 / w;
        int j = from / 2 % w;
        // add horizontal arcs
        if (j - 1 >= 0){
            addArc(from, i, j - 1, 0, d);
        }
        if (j + 1 < w){
            addArc(from, i, j + 1, 0, d);
        }
        // add vertical arcs
        if (i - 1 >= 0){
            addArc(from, i - 1, j, 1, 1 - d);
        }
        if (i + 1 < h){
            addArc(from, i + 1, j, 1, 1 - d);
        }

    }

    void addNullArcs(int from){
        int i = from / 2 / w;
        int j = from / 2 % w;
        // add horizontal arcs
        if (j - 1 >= 0){
            addArc(from, i, j - 1, 0, 0);
        }
        if (j + 1 < w){
            addArc(from, i, j + 1, 0, 0);
        }
        // add vertical arcs
        if (i - 1 >= 0){
            addArc(from, i - 1, j, 1, 0);
        }
        if (i + 1 < h){
            addArc(from, i + 1, j, 1, 0);
        }

    }

    PastureGraph(PastureMatrix m) {
        h = m.size();
        w = m[0].size();
        vertices = w * h * 2;

        bool first_cow = true;

        // Initialize m x n x 2 vertices
        for (auto row : m){
            for (auto c : row){
                vector<Arc> row_a, row_b;
                v.push_back(row_a);
                v.push_back(row_b);
                vertex_type.push_back(c);
                if (first_cow and c == 'C'){
                    vertex_type.push_back('*');
                    first_cow = false;
                } else {
                    vertex_type.push_back(c);
                }
            }
        }

        for (int i = 0; i < vertices; i++){
            if (vertex_type[i] == 'C'){
                addNullArcs(i);
            } else if (vertex_type[i] != '*'){
                addOutgoingArcs(i);
            }
        }
    }

};

int findACow(PastureGraph g){
    for (int i = 0; i < g.vertices; i++){
        if (g.vertex_type[i] == 'C'){
            return i;
        }
    }
    return -1;
}


int distanceToAnotherCow(PastureGraph g, int starting_cow){
    vector<bool> visited(g.vertices, false);
    vector<int> distance(g.vertices, g.vertices * 3); // Impossibly large
    distance[starting_cow] = 0;

    int current = starting_cow;

    while (current == starting_cow or g.vertex_type[current] != 'C'){
        for (Arc a : g.v[current]){
            int new_dist = a.value + distance[current];
            if (distance[a.to] > new_dist){
                distance[a.to] = new_dist;
            }
        }
        visited[current] = true;

        int next;
        int next_distance = g.vertices * 3;
        for (int i = 0; i < g.vertices; i++){
            if (not visited[i] and distance[i] < next_distance){
                next = i;
                next_distance = distance[i];
            }
        }
        current = next;
    }

    return distance[current];
}



int main(){
    PastureMatrix p = readPasture();
    PastureGraph g(p);

    int starting_cow = findACow(g);
    int result = distanceToAnotherCow(g, starting_cow);

    cout << result << "\n";

    return 0;
}
