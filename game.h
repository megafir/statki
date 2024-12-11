#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

void ClearScreen();
void placeShips(Board &board, Player &player);
void playerTurn(Board &opponentBoard, Board &playerBoard);

#endif
