#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct Contestant {
    int id, str, initial;
    queue<int> wins;
    Contestant() { }
    Contestant(int _id, int _str) : id(_id), str(_str), initial(_str) { }
};

void manage_winner(Contestant &w, Contestant &l, int k) {
    w.str -= l.str;
    w.wins.push(l.id);
    w.str += k;
    if(w.str > w.initial)
        w.str = w.initial;

}

int main() {
    int t, n, k;
    int str;
    queue<Contestant> contest;

    cin >> t;

    for(int i = 0; i < t; ++i) {
        cin >> n >> k;

        for(int j = 1; j <= pow(2, n); ++j) {
            cin >> str;
            contest.push(Contestant(j, str));
        }

        Contestant winner, player1, player2;
        for(;;) {
            player1 = contest.front();
            contest.pop();
            player2 = contest.front();
            contest.pop();

            Contestant &w = player1;
            if(player1.str > player2.str) {
                manage_winner(player1, player2, k);
            }
            else if(player1.str < player2.str) {
                manage_winner(player2, player1, k);
                w = player2;
            }
            else if(player1.id < player2.id) {
                manage_winner(player1, player2, k);
            }
            else {
                manage_winner(player2, player1, k);
                w = player2;
            }

            if(contest.empty()) {
                winner = w;
                break;
            }
            else
                contest.push(w);
        }

        cout << winner.id << "\n";
        cout << winner.wins.front();
        winner.wins.pop();
        while(!winner.wins.empty()) {
            cout << " " << winner.wins.front();
            winner.wins.pop();
        }
        cout << "\n";
    }

    return 0;
}
