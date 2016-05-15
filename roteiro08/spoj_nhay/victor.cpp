#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using std::min;
using std::cin;
using std::cout;
using std::vector;
using std::string;

int prefixIsSuffix(string needle, int size, int end){
    for(int i = 0, j = end - size; i < size; i++, j++){
        if (needle[i] != needle[j]){
            return false;
        }
    }
    return true;
}

vector<int> partialMatchTable(string needle){
    vector<int> pmt(needle.size() + 1);
    pmt[0] = -1;
    pmt[1] = 0;
    for (int i = 1; i < needle.size(); i++){
        int max_prefix = min(needle.size() - 1, pmt[i]);
        int best_valid_prefix = 0;
        for (int prefix_size = max_prefix; prefix_size > 0; prefix_size--){
            if (prefixIsSuffix(needle, prefix_size, i + 1)){
                best_valid_prefix = prefix_size;
            }
        }
        pmt[i + 1] = best_valid_prefix;
    }
    return pmt;
}

void runCase(int n){
    string needle;
    cin >> needle;
    vector<int> pmt = partialMatchTable(needle);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), "\n");
    char c;
    int i = 0;
    int j = 0;
    int matches = 0;
    while (true){
        cin.get(c);
        j++;
        if (c == '\n'){
            break;
        }
        if (needle[i] == c){
            i++;
            if (i == needle.size()){
                cout << j << "\n";
                i =
            }
        }
    }
    cout << "\n";
}

int main(){
    int n;
    while (cin >> n){
        runCase(n);
    }
    return 0;
}
