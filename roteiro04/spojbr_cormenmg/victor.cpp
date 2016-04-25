#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

const int adams_number = 42;

int countAdamsWords(){
    int letter_count;
    cin >> letter_count;

    vector<int> counts;

    int begin = 0;
    int adams_count = 0;

    for (int i = 0; i < letter_count; i++){
        int letter;
        cin >> letter;

        for (int j = begin; j < i; j++){
            counts[j] += letter;
            if (counts[j] == adams_number){
                adams_count++;
                begin = i + 1;
                break;
            }
            if (counts[j] >= adams_number){
                begin = j + 1;
            }
        }

        counts.push_back(letter);
    }

    return adams_count;
}

int main(){
    int sections;
    cin >> sections;

    while (sections--){
        int res = countAdamsWords();
        cout << res << "\n";
    }

    return 0;
}
