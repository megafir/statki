#include "board.h"
#include <iostream>

using namespace std;

Board::Board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = '~';         // Ustawienie poczatkowego stanu planszy
            targetBoard[i][j] = '~';   // Ustawienie poczatkowego stanu planszy celu
        }
    }
}

void Board::displayBoard()
{
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Board::displayTargetBoard()
{
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << targetBoard[i][j] << " ";
        }
        cout << endl;
    }
}

bool Board::shoot(int x, int y)
{
    if (board[x][y] == 'S')
    {
        targetBoard[x][y] = 'X'; // Trafiony
        return true;
    }
    else
    {
        targetBoard[x][y] = 'O'; // Nietrafiony
        return false;
    }
}

bool Board::placeShip(int x, int y, int shipLength, char direction)
{
    if (direction == 'H' || direction == 'h') // Poziomo
    {
        if (y + shipLength > SIZE)
            return false;

        for (int i = 0; i < shipLength; i++)
        {
            if (board[x][y + i] != '~')
                return false;
        }

        for (int i = 0; i < shipLength; i++)
        {
            board[x][y + i] = 'S';
        }
    }
    else if (direction == 'V' || direction == 'v') // Pionowo
    {
        if (x + shipLength > SIZE)
            return false;

        for (int i = 0; i < shipLength; i++)
        {
            if (board[x + i][y] != '~')
                return false;
        }

        for (int i = 0; i < shipLength; i++)
        {
            board[x + i][y] = 'S';
        }
    }
    else
    {
        return false; // Zła orientacja
    }

    return true;
}

bool Board::checkWin()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'S')
            {
                return false; // Sa jeszcze statki na planszy
            }
        }
    }
    return true; // Brak statków na planszy
}
