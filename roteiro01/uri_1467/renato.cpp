#include <iostream>

int main() {
    int a, b, c, sum;
    char val;

    for(;;) {
        std::cin >> a >> b >> c;
        if(std::cin.eof())
            break;

        sum = a + b + c;
        if(sum == 1) {
            // One won.
            if(a == 1) val = 'A';
            if(b == 1) val = 'B';
            if(c == 1) val = 'C';
        }
        else if(sum == 2) {
            // Zero won.
            if(a == 0) val = 'A';
            if(b == 0) val = 'B';
            if(c == 0) val = 'C';
        }
        else {
            val = '*';
        }

        std::cout << val << '\n';
    }

    return 0;
}
