#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string name)
{
    this->name = name;
}

void Player::takeTurn(Board &opponentBoard)
{
    int x, y;
    cout << name << ", enter shot coordinates (x y): ";
    cin >> x >> y;

    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
    {
        if (opponentBoard.shoot(x, y))
        {
            cout << "Hit!" << endl;
        }
        else
        {
            cout << "Miss!" << endl;
        }
    }
    else
    {
        cout << "Invalid coordinates. Try again." << endl;
    }
}
