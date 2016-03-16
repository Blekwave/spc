#include <iostream>

void hanoisim(int n, int orig, int dest, int temp, int &moves){
    if (n == 1){
        moves++;
    } else {
        hanoisim(n - 1, orig, temp, dest, moves);
        moves++;
        hanoisim(n - 1, temp, dest, orig, moves);
    }
}

int main(){
    int test_number = 1;
    while (true){
        int n;
        std::cin >> n;
        if (n == 0){
            break;
        }

        int moves = 0;
        hanoisim(n, n, 0, 0, moves); 

        std::cout << "Teste " << test_number << "\n" << moves << "\n\n";

        test_number++;
    }
}
