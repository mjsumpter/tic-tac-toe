#include "game.h"
#include <array>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::string;

array<array<char, len>, len> Game::initialize_gameboard()
{
    array<array<char, len>, len> gameboard;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            gameboard[i][j] = ' '; // initialize gameboard with empty spaces
        }
    }
    return gameboard;
}

Game::Game()
{
    gameboard = initialize_gameboard(); // 2D array of chars representing game board
    current = Player::O;                // keeps track of current player
    gameover = false;                   // flag for win condition
    spaces_used = 0;                    // keeps track of how many spaces on board are filled
    no_winner = false;
}

void Game::print_gameboard()
{
    string horiz_line = "+---+---+---+\n";
    cout << '\n'
         << horiz_line;

    for (auto row : gameboard)
    {
        cout << "|";
        for (char space : row)
        {
            cout << " " << space << " |"; // for each cell, print gameboard structure. @space is space character from @gameboard
        }
        cout << "\n"
             << horiz_line;
    }
}

void Game::take_turn()
{
    int row, column;
    cout << '\n'
         << static_cast<char>(current) << "\'s turn\n";
    while (true) // receive empty cell
    {
        while (true) // receive valid row
        {
            cout << "Pick a row (1, 2, 3): ";
            cin >> row;
            --row; // decrement for backend operations
            if (row < 0 || row > 2)
            {
                cout << "Invalid row. Please enter 1, 2, or 3.\n";
                continue;
            }
            else
            {
                break;
            }
        }
        while (true) // receive valid column
        {
            cout << "Pick a column (1, 2, 3): ";
            cin >> column;
            --column; //decrement for backend operations
            if (column < 0 || column > 2)
            {
                cout << "Invalid column. Please enter 1, 2, or 3.\n";
                continue;
            }
            else
            {
                break;
            }
        }
        if (gameboard[row][column] == ' ') // if selected cell is empty
        {
            gameboard[row][column] = static_cast<char>(current); // assign current player symbol to cell
            ++spaces_used;                                       // update available board space
            return;
        }
        else // if selected cell is filled
        {
            cout << "\nRow " << row + 1 << ", column " << column + 1 << " has already been selected. Try again.\n\n"; // increment row and column for user display
            continue;
        }
    }
}

void Game::check_for_win()
{
    for (int i = 0; i < len; i++)
    {
        if (gameboard[i][0] == gameboard[i][1] &&
            gameboard[i][0] == gameboard[i][2] && // check horizonal match
            gameboard[i][0] != ' ')               // that aren't empty
        {
            gameover = true;
            return;
        }
        if (gameboard[0][i] == gameboard[1][i] &&
            gameboard[0][i] == gameboard[2][i] && // check vertical win condition
            gameboard[0][i] != ' ')
        {
            gameover = true;
            return;
        }
    }

    if (gameboard[0][0] == gameboard[1][1] &&
        gameboard[0][0] == gameboard[2][2] && // check forward diagonal win condition
        gameboard[0][0] != ' ')
    {
        gameover = true;
        return;
    }

    if (gameboard[2][0] == gameboard[1][1] &&
        gameboard[2][0] == gameboard[0][2] && // check backwards diagonal win condition
        gameboard[2][0] != ' ')
    {
        gameover = true;
        return;
    }

    if (spaces_used == 9) // if board is full
    {
        no_winner = gameover = true;
        return;
    }
}

void Game::change_player()
{
    if (current == Player::X)
        current = Player::O;
    else
        current = Player::X;
}

void Game::end_game()
{
    if (no_winner)
    {
        cout << "\nIt's a tie! No one wins.\n";
    }
    else
    {
        cout << static_cast<char>(current) << " wins!\n";
    }
    cout << "Game over!\n\n";
}