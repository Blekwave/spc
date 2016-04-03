#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

const int MAX_SIZE_BOARD = 100;
const int MAX_TRACKS_QTD = 100;

void inicializeBoard(int board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int N);
void findTreasurePosition(int board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int N, int K, std::vector<std::pair<int, int> > tracks);
int calcDistance(int pointX, int pointY, int trackX, int trackY);

int main()  {
	int N, K, X, Y, D,
		numberOfTracks = 0,
		board[MAX_SIZE_BOARD][MAX_SIZE_BOARD];

	std::vector<std::pair<int, int> > tracks(MAX_TRACKS_QTD);
	std::pair<int, int> currentCoordinate;

	std::cin >> N >> K;
	inicializeBoard(board, N);

	while(numberOfTracks < K)  {
		std::cin >> X >> Y >> D;
        board[X][Y] = D;
        currentCoordinate = std::make_pair(X, Y);
        tracks[numberOfTracks] = currentCoordinate;
        numberOfTracks++;
	}

	findTreasurePosition(board, N, K, tracks);

	return 0;
}

void inicializeBoard(int board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int N)  {
	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			board[i][j] = 0;
		}
	}
}

void findTreasurePosition(int board[MAX_SIZE_BOARD][MAX_SIZE_BOARD], int N, int K, std::vector<std::pair<int, int> > tracks)  {
	int currentDistance = 0,
		possibleTreasurePoints = 0,
		lowestValue = -1;
	std::pair<int, int> treassureCoordinate;

	for(int i = 0; i < N; i++)  {
		for(int j = 0; j < N; j++)  {
			for(int k = 0; k < K; k++)  {
				if((i != tracks[k].first || j != tracks[k].second) && board[i][j] <= 0)  {
					currentDistance = calcDistance(i, j, tracks[k].first, tracks[k].second);
					if(currentDistance == board[tracks[k].first][tracks[k].second])  {
						board[i][j]--;
					}
				}
			}
			if(board[i][j] <= lowestValue)  {
				if(board[i][j] == lowestValue)
					possibleTreasurePoints++;
				else
					possibleTreasurePoints = 0;
				lowestValue = board[i][j];
				treassureCoordinate = std::make_pair(i, j);
			}
		}
	}

	if(possibleTreasurePoints == 0)
		std::cout << treassureCoordinate.first << " " << treassureCoordinate.second << "\n";
	else
		std::cout << "-1 -1\n";

}

int calcDistance(int pointX, int pointY, int trackX, int trackY)  {
	int distance = 0;
	distance += std::abs(pointX - trackX) + std::abs(pointY - trackY);
	return distance;
}
