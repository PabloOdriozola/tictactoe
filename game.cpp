#include "game.h"


void initGame() {
    // Create board and initialize it with empty variants
    std::fill(board.begin(),board.end(), Cell::Empty);

    winningCombinations = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };
}

void playTurn(int cellIndex) {
 // Knowing which cell has been clicked
    if (turn == PLAYER1) {
        board[cellIndex] = Cell::X;
    } else {
        board[cellIndex] = Cell::O;
    }
}

bool checkWin() {
    for (const auto& combination: winningCombinations) {
        if (board[combination[0]] == board[combination[1]] &&
            board[combination[1]] == board[combination[2]] &&
            board[combination[0]] != Cell::Empty) {
            return true; // Win
        }
    }
    turn = !turn; // Next player's turn
    return false; // Not over yet
}
