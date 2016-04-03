/*
    Armazenamos o tabuleiro em uma matriz. As posições
    das nossas peças também são armazenadas em um vetor
    para facilitar sua varredura. Para cada peça nossa
    existente, utilizamos backtracking para checar todas
    as formas possíveis de movimentá-la: Usamos uma função
    recursiva que move uma peça para uma posição e chama a si
    mesma para cada movimento possível restante. Caso
    não haja nenhum movimento restante, a função retorna 0,
    indicando que não é possível ganhar mais nenhuma peça a
    partir dali. Do contrário, retorna a quantidade de peças
    que podem ser ganhas a partir dessa posição.
*/

#include <iostream>
#include <vector>
#include <utility>

void clearBoard(int board[20][20]) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            board[i][j] = 0;
        }
    }
}

int calcStreak(int board[20][20], std::pair<int,int> piece, int N, int M) {
    int longestStreak = 0;
    int streak;
    int i = piece.first,
        j = piece.second;

    if((i - 2 >= 0) && (j - 2 >= 0) && (board[i-1][j-1] == 2) && (board[i-2][j-2] == 0)) {
        // move upwards-leftwards
        board[i][j] = 0;
        board[i-1][j-1] = 0;
        board[i-2][j-2] = 1;
        streak = calcStreak(board, std::pair<int,int>(i-2, j-2), N, M) + 1;
        board[i][j] = 1;
        board[i-1][j-1] = 2;
        board[i-2][j-2] = 0;
        if(streak > longestStreak) longestStreak = streak;
    }
    if((i - 2 >= 0) && (j + 2 < M) && (board[i-1][j+1] == 2) && (board[i-2][j+2] == 0)) {
        // move upwards-rightwards
        board[i][j] = 0;
        board[i-1][j+1] = 0;
        board[i-2][j+2] = 1;
        streak = calcStreak(board, std::pair<int,int>(i-2, j+2), N, M) + 1;
        board[i][j] = 1;
        board[i-1][j+1] = 2;
        board[i-2][j+2] = 0;
        if(streak > longestStreak) longestStreak = streak;
    }
    if((i + 2 < N) && (j - 2 >= 0) && (board[i+1][j-1] == 2) && (board[i+2][j-2] == 0)) {
        // move downwards-leftwards
        board[i][j] = 0;
        board[i+1][j-1] = 0;
        board[i+2][j-2] = 1;
        streak = calcStreak(board, std::pair<int,int>(i+2, j-2), N, M) + 1;
        board[i][j] = 1;
        board[i+1][j-1] = 2;
        board[i+2][j-2] = 0;
        if(streak > longestStreak) longestStreak = streak;
    }
    if((i + 2 < N) && (j + 2 < M) && (board[i+1][j+1] == 2) && (board[i+2][j+2] == 0)) {
        // move downwards-rightwards
        board[i][j] = 0;
        board[i+1][j+1] = 0;
        board[i+2][j+2] = 1;
        streak = calcStreak(board, std::pair<int,int>(i+2, j+2), N, M) + 1;
        board[i][j] = 1;
        board[i+1][j+1] = 2;
        board[i+2][j+2] = 0;
        if(streak > longestStreak) longestStreak = streak;
    }

    return longestStreak;
}

int main() {
    int board[20][20];

    int N, M;

    while(true) {
        std::vector<std::pair<int,int> > playerPieces;
        int longestStreak = 0;
        std::cin >> N >> M;

        if(N == 0) break;
        clearBoard(board);

        for(int i = 0; i < N; i++) {
            for(int j = i % 2; j < M; j+=2) {
                std::cin >> board[i][j];
                if(board[i][j] == 1) playerPieces.push_back(std::pair<int,int> (i, j));
            }
        }

        for(int i = 0; i < playerPieces.size(); i++) {
            int streak = calcStreak(board, playerPieces[i], N, M);
            if(streak > longestStreak) longestStreak = streak;
        }

        std::cout << longestStreak << " \n";

    }

    return 0;
}