#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> Coord;


void runTest(int k){
    int dx, dy;
    cin >> dx >> dy;
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        if (x == dx or y == dy){
            cout << "divisa";
        } else if (x < dx){
            if (y < dy){
                cout << "SO";
            } else {
                cout << "NO";
            }
        } else {
            if (y < dy){
                cout << "SE";
            } else {
                cout << "NE";
            }
        }
        cout << "\n";
    }
}

int main(){
    int k;
    while (true){
        cin >> k;
        if (k == 0){
            break;
        }

        runTest(k);
    }

    return 0;
}
