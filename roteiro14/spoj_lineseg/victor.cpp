#include <iostream>
#include <algorithm>

using namespace std;

struct OrdPair {
    int x;
    int y;
};

void runCase(){
    OrdPair a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y
        >> b1.x >> b1.y >> b2.x >> b2.y;

    if (a1.x > a2.x or a1.y > a2.y){
        swap(a1, a2);
    }
    if (b1.x > b2.x or b1.y > b2.y){
        swap(b1, b2);
    }

    bool a_hor = a1.y == a2.y;
    bool b_hor = b1.y == b2.y;

    if (not a_hor){
        swap(a1.x, a1.y);
        swap(a2.x, a2.y);
        swap(b1.x, b1.y);
        swap(b2.x, b2.y);
    }

    a_hor = a1.y == a2.y;
    b_hor = b1.y == b2.y;

    // A é horizontal daqui em diante
    /* cout << "a1 " << a1.x << " " << a1.y << "\n"; */
    /* cout << "a2 " << a2.x << " " << a2.y << "\n"; */
    /* cout << "b1 " << b1.x << " " << b1.y << "\n"; */
    /* cout << "b2 " << b2.x << " " << b2.y << "\n"; */
    if (not b_hor){ // b vertical
        /* cout << "here\n"; */
        if (b1.x >= a1.x and b1.x <= a2.x and a1.y >= b1.y and a1.y <= b2.y){
            cout << "POINT\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (a1.y != b1.y){
            cout << "NO\n";
        } else if (a2.x == b1.x or b2.x == a1.x){
            cout << "POINT\n";
        } else if (a1.x >= b1.x and a1.x < b2.x){
            if (a2.x == a1.x){
                cout << "POINT\n";
            } else {
                cout << "SEGMENT\n";
            }
        } else if (b1.x >= a1.x and b1.x < a2.x){
            if (b2.x == b1.x){
                cout << "POINT\n";
            } else {
                cout << "SEGMENT\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}

int main(){
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++){
        runCase();
    }
    return 0;
}
