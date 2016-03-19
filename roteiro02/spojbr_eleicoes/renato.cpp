#include <iostream>
#include <map>
using namespace std;

int main() {
    std::map<int, int> votes;
    int n, input;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        votes[input] += 1;
    }

    std::map<int, int>::iterator winner, it;
    for(it = votes.begin(), winner = votes.begin(); it != votes.end(); ++it) {
        if(it->second > winner->second)
            winner = it;
    }

    cout << winner->first << "\n";
    return 0;
}
