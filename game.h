#ifndef GAME_H
#define GAME_H
#include <array>

// Players' turns
#define PLAYER1 true // X player
#define PLAYER2 false // O player

// Possible cell variations, the board will start with 9 empty variant cells which will be overwritten
// each turn with "X" or "O" variants
enum class Cell {
    Empty,
    X,
    O
};



std::array<Cell, 9> board; // Tictactoe board array
std::array<std::array<int, 3>, 8> winningCombinations = { // Array of winning combinations
    {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
    {0, 4, 8}, {2, 4, 6}}              // diagonals
};

#endif // GAME_H
