#include <cstdio>

// Clockwise.
int direction[][2] = {
    {0, 1}, // Looking right.
    {1, 0},
    {0, -1},
    {-1, 0}
};

int main() {
    int pos[2];
    int dir, instr, figures, x, y;
    int n, m, s;
    char board[100][100];

    for(;;) {
        scanf("%d%d%d%*c", &n, &m, &s);
        if(n == 0 && m == 0 && s == 0)
            break;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] = getchar();
                if(board[i][j] == 'O' || board[i][j] == 'S'
                        || board[i][j] == 'L' || board[i][j] == 'N') {
                    pos[0] = i;
                    pos[1] = j;

                    if(board[i][j] == 'L') dir = 0;
                    else if(board[i][j] == 'S') dir = 1;
                    else if(board[i][j] == 'O') dir = 2;
                    else if(board[i][j] == 'N') dir = 3;
                }
            }
            getchar(); // discard '\n'.
        }

        figures = 0;
        for(int i = 0; i < s; ++i) {
            instr = getchar();

            if(instr == 'D') {
                dir = (dir + 1) % 4;
            }
            else if(instr == 'E') {
                dir = (dir + 3) % 4;
            }
            else {
                y = pos[0] + direction[dir][0];
                x = pos[1] + direction[dir][1];
                if(y < 0 || x < 0 || y >= n || x >= m || board[y][x] == '#')
                    continue;

                if(board[y][x] == '*') {
                    board[y][x] = '.';
                    ++figures;
                }

                pos[0] = y;
                pos[1] = x;
            }
        }

        printf("%d\n", figures);
        getchar();
    }

    return 0;
}
