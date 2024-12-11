#include <iostream>
#include "game.h"

using namespace std;

void ClearScreen()
{
    system("cls");
}

void placeShips(Board &currentplayerboard, Player &currentplayer)
{
    int x, y;
    char direction;

    // Liczba statków i ich długości
    int shipCounts[] = {1, 2, 3, 4}; // Liczba statków: 4-masztowiec, 3-masztowce, 2-masztowce, itd.
    int shipLengths[] = {4, 3, 2, 1}; // Długości statków: 4, 3, 2, 1

    for (int i = 0; i < 4; i++) // Iteracja przez różne typy statków
    {
        for (int j = 0; j < shipCounts[i]; j++) // Rozmieszczanie każdego typu statku
        {
            bool placed = false;
            while (!placed)
            {
                cout << "Place your " << shipLengths[i] << "-mast ship #" << (j + 1)
                     << " (x [space] y [space] direction [H/V]): ";
                cin >> x >> y >> direction;
                if ( (x >= 0 && x <=9) && (y >= 0 && y <=9) && ((direction == 'H' || direction == 'h') || (direction == 'V' || direction == 'v')) )
                {
                    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
                    {
                        placed = currentplayerboard.placeShip(x, y, shipLengths[i], direction);
                        if (placed)
                        {
                            cout << "Ship placed successfully! Current board:" << endl;
                            currentplayerboard.displayBoard(); // Wyświetlanie planszy po rozmieszczeniu statku
                        }
                        else
                        {
                            cout << "Invalid position or collision. Try again." << endl;\
                        }
                    }
                    else
                    {
                        cout << "Coordinates out of bounds. Try again." << endl;
                    }
                }
                else
                {
                    cout << "Wrong format! Please enter x and y as a number followed by H or V." << endl;
                }
            }
        }
    }
}

void playerTurn(Board &opponentBoard, Board &playerBoard)
{
    playerBoard.displayTargetBoard();
    int x, y;
    cout << "Enter shot coordinates (x y): ";
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
        playerBoard.displayTargetBoard(); 
        cout << "Gracz, odejdź od stanowiska. Naciśnij Enter, aby kontynuować..." << endl;
        cin.ignore();  // Oczekiwanie na naciśnięcie Enter
        cin.get(); // Czekamy na naciśnięcie klawisza Enter
        ClearScreen();
    }
    else
    {
        cout << "Invalid coordinates. Try again." << endl;
    }
}
