#include <iostream>
#include "game.cc"
#include "player.cc"
#include "board.cc"

using namespace std;

int main()
{
    Board player1Board,player2Board;
    // Tworzymy graczy
    Player player1("Gracz 1");
    Player player2("Gracz 2");

    // Gracz 1 ustawia statki
   // Gracz 1 ustawia statki
cout << "Player 1, place your ships!" << endl;

placeShips(player1Board, player1); // Rozmieszczanie statkow przez gracza 1
cout << "Player 1's final board:" << endl;
player1Board.displayBoard(); // Wyświetlenie planszy gracza 1 po rozmieszczeniu statków
cout << "Gracz 1, odejdz od stanowiska. Nacisnij Enter, aby kontynuowac..." << endl;
cin.ignore();  // Oczekiwanie na naciśnięcie Enter
cin.get(); // Czekamy na naciśnięcie klawisza Enter
ClearScreen(); // Czyszczenie ekranu 
// Gracz 2 ustawia statki
cout << "Player 2, place your ships!" << endl;
Board(); 
placeShips(player2Board, player2); // Rozmieszczanie statków przez gracza 2
cout << "Player 2's final board:" << endl;
player2Board.displayBoard(); // Wyświetlenie planszy gracza 2 po rozmieszczeniu statków
cout << "Gracz 2, odejdz od stanowiska. Nacisnij Enter, aby kontynuowac..." << endl;
cin.ignore();  // Oczekiwanie na naciśnięcie Enter
cin.get(); // Czekamy na naciśnięcie klawisza Enter
ClearScreen(); // Czyszczenie ekranu

    int turn = 0;
    while (true)
    {
        if (turn % 2 == 0)
        {
            cout << "Gracz 1, Twoja tura!" << endl;
            player1.takeTurn(player2Board);
            if (player2Board.checkWin())
            {
                cout << "Gracz 1 wygral!" << endl;
                break;
            }
        }
        else
        {
            cout << "Gracz 2, Twoja tura!" << endl;
            player2.takeTurn(player1Board);
            if (player1Board.checkWin())
            {
                cout << "Gracz 2 wygral!" << endl;
                break;
            }
        }
        turn++;
    }

    return 0;
}
