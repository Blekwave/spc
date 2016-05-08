#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::max;

typedef vector<bool> BoolMatrixRow;
typedef vector<BoolMatrixRow> BoolMatrix;

typedef vector<int> IntMatrixRow;
typedef vector<IntMatrixRow> IntMatrix;


vector<BoolMatrix> readFalls(int rows, int cols, int apples){
    BoolMatrix prototype = BoolMatrix(rows, BoolMatrixRow(cols, false));
    vector<BoolMatrix> falls(1, prototype);
    for (int i = 0; i < apples; i++){
        int row, col, fall_time;
        cin >> row >> col >> fall_time;
        row--; col--;
        if (falls.size() <= fall_time){
            vector<BoolMatrix> newFalls(fall_time - falls.size() + 1, prototype);
            falls.insert(falls.end(), newFalls.begin(), newFalls.end());
        }
        falls[fall_time][row][col] = true;
    }
    return falls;
}

bool checkPos(int rows, int cols, int row, int col){
    return row >= 0 and row < rows and col >= 0 and col < cols;
}

int bestAdjacent(IntMatrix &prev, int row, int col){
    int rows = prev.size(), cols = prev[0].size();
    int best_val = -1;
    for (int drow = -1; drow <= 1; drow++){
        for (int dcol = -1; dcol <= 1; dcol++){
            if (checkPos(rows, cols, row + drow, col + dcol)){
                best_val = max(best_val, prev[row + drow][col + dcol]);
            }
        }
    }
    return best_val;
}

int runCase(int rows, int cols, int apples){
    vector<BoolMatrix> falls = readFalls(rows, cols, apples);
    int starting_row, starting_col;
    IntMatrix prev(rows, IntMatrixRow(cols, -1));
    cin >> starting_row >> starting_col;
    starting_row--; starting_col--;
    prev[starting_row][starting_col] = 0;

    for (int time = 1; time < falls.size(); time++){
        IntMatrix next(prev);
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                int best_adj = bestAdjacent(prev, row, col);
                if (best_adj > -1){
                    best_adj += falls[time][row][col];
                }
                next[row][col] = best_adj;
            }
        }
        prev = next;
    }

    int best_val = 0;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            best_val = max(best_val, prev[row][col]);
        }
    }

    return best_val;
}


int main(){
    int rows, cols, apples;
    while (true){
        cin >> rows >> cols >> apples;
        if (rows == 0 and cols == 0 and apples == 0){
            break;
        }

        int result = runCase(rows, cols, apples);
        cout << result << "\n";
    }

    return 0;
}
