#include <iostream>

const int N = 9;
int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
const int original_board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};
void printBoard() {
    std::cout << "\n    1 2 3   4 5 6   7 8 9 (Columns)\n";
    std::cout << "  -------------------------\n";
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            std::cout << "  |-------+-------+-------|\n";
        }
        std::cout << row + 1 << " | "; 
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                std::cout << "| ";
            }
            if (board[row][col] == 0)
                std::cout << ". "; 
            else
                std::cout << board[row][col] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "  -------------------------\n";
}
bool isValidMove(int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) return false;
    }
    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}
bool isGameOver() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

int main() {
    std::cout << "=====================================\n";
    std::cout << "     WELCOME TO INTERACTIVE SUDOKU    \n";
    std::cout << "=====================================\n";
    std::cout << "Rules: Enter Row (1-9), Column (1-9), and Number (1-9).\n";
    std::cout << "Enter 0 as number to clear a cell you filled.\n";

    while (!isGameOver()) {
        printBoard();

        int row, col, num;
        std::cout << "\nEnter Row (1-9): ";
        std::cin >> row;
        std::cout << "Enter Column (1-9): ";
        std::cin >> col;
        std::cout << "Enter Number (1-9, or 0 to erase): ";
        std::cin >> num;

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 0 || num > 9) {
            std::cout << "\nInvalid input! Please enter numbers between 1 and 9.\n";
            continue;
        }
        int r = row - 1;
        int c = col - 1;
    if (original_board[r][c] != 0) {
            std::cout << "\nOops! Yeh number pehle se fixed he, aap isko change nahi kar sakte.\n";
            continue;
        }
        if (num == 0) {
            board[r][c] = 0;
            std::cout << "\n Cell cleared!\n";
            continue;
        }
        if (isValidMove(r, c, num)) {
            board[r][c] = num;
            std::cout << "\nMove accepted!\n";
        } else {
            std::cout << "\nWrong Move! Sudoku ke rules ke mutabiq yeh number yahan nahi aa sakta.\n";
        }
    }
    printBoard();
    std::cout << "\n CONGRATULATIONS! Aap ne Sudoku perfectly solve kar liya! 🎉\n";
    return 0;
}