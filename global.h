#ifndef GLOBAL_H
#define GLOBAL_H

extern bool turn; // Global variable which will rotate between true and false to decide each player's turn
extern short turnNum; // Turn index from [1 to 9]

void initGame(); // Initialize the game setting up the board
void playTurn(int cellIndex); // Fill the clicked empty square of the board with "X" or "O" according to players' turn

#endif // GLOBAL_H
