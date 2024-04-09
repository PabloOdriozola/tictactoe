#include "game.h"
#include "global.h"

bool turn;
short turnNum;
std::array<int, 3> winnerCombo;

void initGame() {
    // Create board and initialize it with empty variants
    board = {Cell::Empty};

    turn = PLAYER1; // First turn for player X
    turnNum = 1; // Turn counter

    winnerCombo = {0}; // Winner combo is unkown yet
}

void playTurn(int cellIndex) {
    // Knowing which cell has been clicked...
    if (turn == PLAYER1) {
        board[cellIndex] = Cell::X;
    } else {
        board[cellIndex] = Cell::O;
    }

    turnNum++; // Turn counter up
    turn = !turn; // Next player's turn
}

bool checkWin() {
    // If any of the possible winning combinations contains the same Cell variant except Empty (i.e. X or O)
    for (const auto& combination: winningCombinations) {
        if (board[combination[0]] == board[combination[1]] &&
            board[combination[1]] == board[combination[2]] &&
            board[combination[0]] != Cell::Empty) {

            winnerCombo = {combination[0], combination[1], combination[2]};
            return true; // Win
        }
    }
    return false; // Not over yet
}

void restartGame() {
    board = {Cell::Empty}; // Empty the entire board

    turn = PLAYER1; // First turn for player X
    turnNum = 1; // Restart turn counter
}
