#ifndef GLOBAL_H
#define GLOBAL_H

#include <array>

extern bool turn; // Global variable which will rotate between true and false to decide each player's turn
extern short turnNum; // Turn index from [1 to 9]
extern std::array<int, 3> winnerCombo; // Save combination that granted victory

void initGame(); // Initialize the game setting up the board
void playTurn(int cellIndex); // Fill the clicked empty square of the board with "X" or "O" according to players' turn
bool checkWin(); // Check if last's turn movement is a victory
void restartGame(); // Restart game if desired
#endif // GLOBAL_H
