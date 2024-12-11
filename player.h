#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include <string>

using namespace std;

class Player
{
public:
    string name;
    Player(string name);
    void takeTurn(Board &opponentBoard); // Funkcja dla gracza do wykonania tury
};

#endif
