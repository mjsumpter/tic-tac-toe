/* Tic Tac Toe
 * Author: Matthew Sumpter
 * Purpose: A console Tic tac toe simulator.
 * */

#include "game.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
    cout << "Welcome to Tic Tac Toe\n";

    while (true)
    {
        Game game; // start new game

        game.print_gameboard();

        while (!game.check_gameover())
        {
            game.change_player();
            game.take_turn();
            game.print_gameboard();
            game.check_for_win();
        }

        game.end_game();

        char again;
        cout << "Play again? (y/n): ";
        cin >> again;
        cin.ignore(1000, '\n');
        if (tolower(again) == 'n')
            break;
    }

    cout << "Goodbye!" << endl;

    return 0;
}