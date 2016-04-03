#include <iostream>

long long exp2(int exponent){
    long long product = 1;
    for (int i = 0; i < exponent; i++){
        product *= 2;
    }
    return product;
}

int main(){
    int test_number = 1;
    while (true){
        int n;
        std::cin >> n;
        if (n == 0){
            break;
        }

        std::cout << "Teste " << test_number << "\n"
                  << exp2(n) - 1 << "\n\n";

        test_number++;
    }
}
