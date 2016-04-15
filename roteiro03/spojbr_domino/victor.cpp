// A solução proposta cria um mapeamento entre cada peça de dominó (ou seja, o
// par de valores impresso na sua face) e o seu identificador numérico.
// Posteriormente, é lida a matriz de valores dispostos no tabuleiro e o pro-
// grama tenta, por meio de força bruta com backtracking, dispor peças de domi-
// nó de todas as formas possíveis.
// Caso o programa consiga preencher o tabuleiro até o final, sem contradições
// ou repetição de peças, é somado 1 ao contador de tabuleiros válidos. Caso
// contrário, no momento em que não há configurações válidas de peças, o pro-
// grama recua a estados anteriores, desfazendo as jogadas realizadas.


#include <iostream>
#include <map>
#include <array>
#include <stack>
#include <vector>
#include <algorithm> // find
#include <utility> // pair

const int DOMINO_MIN = 0;
const int DOMINO_MAX = 6;

typedef std::pair<int, int> Domino;

const int MATRIX_ROWS = 7;
const int MATRIX_COLS = 8;

typedef std::array<std::array<int, MATRIX_COLS>, MATRIX_ROWS> DominoMatrix;
typedef std::map<Domino, int> DominoIDMap;

const DominoIDMap buildDominoIDMap(){
    DominoIDMap m;
    int piece_id = 1;
    for (int i = DOMINO_MIN; i <= DOMINO_MAX; i++){
        for (int j = i; j <= DOMINO_MAX; j++){
            Domino values(i, j), values_inverted(j, i);
            m[values] = piece_id;
            m[values_inverted] = piece_id;
            piece_id++;
        }
    }
    return m;
}

DominoMatrix readMatrix(){
    DominoMatrix m;
    for (int i = 0; i < MATRIX_ROWS; i++){
        for (int j = 0; j < MATRIX_COLS; j++){
            int val;
            std::cin >> val;
            m[i][j] = val;
        }
    }
    return m;
}

enum class Placement { horizontal = 0, vertical = 1 };
typedef std::pair<int, int> Cell;

struct BFState {
    Placement mode = Placement::horizontal;
    Cell cell = {0, 0};
};

class DominoSolver {
    private:
        DominoMatrix value_matrix;
        DominoMatrix id_matrix;
        std::stack<BFState> stack;
        std::vector<int> used_ids;
        int count = 0;
    public:
        static DominoIDMap id_map;
        DominoSolver(DominoMatrix &m) : value_matrix(m) { }
        int countSolutions();
        bool isViable();
        bool getDominoAndCells(int &domino_id, Cell &cell1, Cell &cell2);
        bool withinBounds(Cell &cell);
        bool commit();
        void advance();
        void backtrack();
};

DominoIDMap DominoSolver::id_map = buildDominoIDMap();

void zeroMatrix(DominoMatrix &matrix){
    for (int i = 0; i < MATRIX_ROWS; i++){
        for (int j = 0; j < MATRIX_COLS; j++){
            matrix[i][j] = 0;
        }
    }
}

int DominoSolver::countSolutions(){
    BFState initial = {Placement::horizontal, {0, 0}};
    stack.push(initial);
    zeroMatrix(id_matrix);

    while(!stack.empty()){
        BFState &current = stack.top();

        if (commit()){
            advance();
        } else if (current.mode == Placement::horizontal){
            current.mode = Placement::vertical;
        } else {
            stack.pop();
            backtrack();
        }
    }

    return count;
}

bool DominoSolver::getDominoAndCells(int &domino_id, Cell &cell1, Cell &cell2){
    BFState &current = stack.top();
    cell1 = current.cell;
    if (current.mode == Placement::horizontal){
        cell2 = {current.cell.first, current.cell.second + 1};
    } else {
        cell2 = {current.cell.first + 1, current.cell.second};
    }

    if (withinBounds(cell2) and id_matrix[cell1.first][cell1.second] == 0 and
        id_matrix[cell2.first][cell2.second] == 0){

        Domino d = {value_matrix[cell1.first][cell1.second],
                    value_matrix[cell2.first][cell2.second]};
        domino_id = id_map[d];

        return true;
    }
    return false;
}

bool DominoSolver::withinBounds(Cell &cell){
    // No need to check if the cell has negative indices, because no subtrac-
    // tions involving indices are performed
    return cell.first < MATRIX_ROWS and cell.second < MATRIX_COLS;
}

bool DominoSolver::commit(){
    Cell cell1, cell2;
    int domino_id;
    if (!getDominoAndCells(domino_id, cell1, cell2)){
        return false;
    }

    if (std::find(used_ids.begin(), used_ids.end(), domino_id) != used_ids.end()){
        return false;
    }

    used_ids.push_back(domino_id);
    id_matrix[cell1.first][cell1.second] = domino_id;
    id_matrix[cell2.first][cell2.second] = domino_id;
    return true;
}

void DominoSolver::advance(){
    BFState &current = stack.top();
    Cell c = current.cell;
    do {
        c.second++;
        if (c.second >= MATRIX_COLS){
            c.second = 0;
            c.first++;
            if (c.first >= MATRIX_ROWS){
                count++;
                backtrack();
                return;
            }
        }
    } while (id_matrix[c.first][c.second] != 0);
    BFState next = {Placement::horizontal, c};
    stack.push(next);
}

void DominoSolver::backtrack(){
    if (stack.empty()){
        return;
    }

    BFState &current = stack.top();
    Cell cell1 = current.cell, cell2;
    if (current.mode == Placement::horizontal){
        cell2 = {cell1.first, cell1.second + 1};
    } else {
        cell2 = {cell1.first + 1, cell1.second};
    }

    int current_id = id_matrix[cell1.first][cell1.second];
    used_ids.erase(std::find(used_ids.begin(), used_ids.end(), current_id));

    id_matrix[cell1.first][cell1.second] = 0;
    id_matrix[cell2.first][cell2.second] = 0;

    if (current.mode == Placement::horizontal){
        current.mode = Placement::vertical;
        return;
    }

    stack.pop();
    backtrack();
}

int main(){
    int num_tests;
    std::cin >> num_tests;
    for (int test_number = 1; test_number <= num_tests; test_number++){
        std::cout << "Teste " << test_number << "\n";
        auto matrix = readMatrix();

        DominoSolver d(matrix);
        int map_count = d.countSolutions();
        std::cout << map_count << "\n\n";
    }

    return 0;
}
