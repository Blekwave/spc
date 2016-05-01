#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string s;
    while (std::cin >> s){
        if (s == "0"){
            break;
        }

        if (s.size() == 1){
            std::cout << "1\n";
            continue;
        }

        std::vector<long long> v = {1,
            (int)(s[1] > '0') + (s[0] == '2' && s[1] <= '6' || s[0] == '1')
        };
        for (unsigned i = 2; i < s.size(); i++){
            long long p = (s[i] > '0') * v[i - 1] +
                          (s[i - 1] == '2' && s[i] <= '6' || s[i - 1] == '1') * v[i - 2];
            v.push_back(p);
        }

        std::cout << v.back() << "\n";
    }
    return 0;
}
