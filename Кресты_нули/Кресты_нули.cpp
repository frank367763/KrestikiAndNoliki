#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));

void displayBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--" << endl;
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

char checkWinner() {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Проверка диагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // Проверка на ничью
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return ' '; // Игра продолжается
        }
    }

    return 'D'; // Ничья (Draw)
}

void makeMove(char player) {
    int row, col;
    do {
        cout << "Игрок " << player << ", введите номер строки и столбца (0-2): ";
        cin >> row >> col;
    } while (!isValidMove(row, col));

    board[row][col] = player;
}

void resetBoard() {
    board = vector<vector<char>>(SIZE, vector<char>(SIZE, ' '));
}