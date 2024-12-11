#ifndef BOARD_H
#define BOARD_H

const int SIZE = 10;

class Board
{
public:
    char board[SIZE][SIZE];
    char targetBoard[SIZE][SIZE]; 
    Board();
    void displayBoard();             // Wyswietlenie planszy gracza
    void displayTargetBoard();       // Wyswietlenie planszy celu
    bool shoot(int x, int y);        // Wykonanie strzalu
    bool placeShip(int x, int y, int shipLength, char direction); // Rozmieszczenie statku
    bool checkWin();                 // Sprawdzenie, czy gracz wygral
};

#endif
