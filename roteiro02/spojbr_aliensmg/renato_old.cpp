#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> dnas;
    int n;
    char c;

    for(;;) {
        std::cin >> n;
        while(std::cin.get(c) && c != '\n') { }
        if(!n) break;

        dnas.clear();
        for(int i = 0; i < n; ++i) {
            std::string str;
            std::getline(std::cin, str);
            std::sort(str.begin(), str.end());
            dnas.push_back(str);
        }
        std::sort(dnas.begin(), dnas.end());

        int diff = 1;
        for(int i = 1; i < n; ++i)
            if(dnas[i] != dnas[i-1])
                ++diff;

        std::cout << diff << "\n";
    }

    return 0;
}
