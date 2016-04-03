#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int PASSWD_SIZE = 6;
const int NUM_LETTERS = 5;
const int OPTIONS_PER_LETTER = 2;

using std::vector;
using std::cin;
using std::cout;
using std::map;
using std::find;

vector<int> intersect(vector<int> &a, vector<int> &b){
    vector<int> intersection;
    for (auto it = a.begin(); it != a.end(); it++){
        if (find(b.begin(), b.end(), *it) != b.end()){
            intersection.push_back(*it);
        }
    }
    return intersection;
}

map<char, vector<int>> readMapping(){
    map<char, vector<int>> mapping;
    for (int i = 0; i < NUM_LETTERS; i++){
        for (int j = 0; j < OPTIONS_PER_LETTER; j++){
            int val;
            cin >> val;
            mapping['A' + i].push_back(val);
        }
    }
    return mapping;
}

int main(){
    int test_number = 1;
    while (true){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }
        
        vector<vector<int>> possible_vals;
        
        auto first_mapping = readMapping();
        for (int j = 0; j < PASSWD_SIZE; j++){
            char letter;
            cin >> letter;
            possible_vals.push_back(first_mapping[letter]);
        }

        for (int i = 1; i < n; i++){
            auto mapping = readMapping();
            for (int j = 0; j < PASSWD_SIZE; j++){
                char letter;
                cin >> letter;
                possible_vals[j] = intersect(possible_vals[j], mapping[letter]);
            }
        }
        
        cout << "Teste " << test_number << "\n";
        for (auto v : possible_vals){
            cout << v[0] << " ";
        }
        cout << "\n\n";

        test_number++;
    }
    return 0;
}
