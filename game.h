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



std::array<Cell, 9> board; // Tictactoe board array
std::vector<std::vector<int>> winningCombinations; // Vector of winning combinations // TODO: Change vector to array or viceversa // TODO: estas 2 ultimas variables no tienen porque ser extern ¿no? // TODO: añadir otra variable que sea un contador de turnos

bool checkWin(); // Will check if last's turn movement is a victory

#endif // GAME_H
