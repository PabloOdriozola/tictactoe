#ifndef GAME_H
#define GAME_H
#include <array>
#include <vector>

// Players' turns
#define PLAYER1 true // X player
#define PLAYER2 false // O player

// Definition of enum for game variations
enum class Cell {
    Empty,
    X,
    O
};



bool turn; // Global variable which will rotate between true and false to decide each player's turn
using Board = std::array<Cell, 9>; // Tictactoe board alias
std::vector<std::vector<int>> winningCombinations; // Vector of winning combinations
Board board;

void initGame(); // Initialize the game setting up the board
void playTurn(int cellIndex); // Fill the clicked empty square of the board with "X" or "O" according to players' turn
bool checkWin(); // Will check if last's turn movement is a victory

#endif // GAME_H
