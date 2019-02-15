#ifndef GAME_H
#define GAME_H

#include <array>

const unsigned short len = 3; // Tic tac toe board is 3 x 3

using std::array;

enum class Player : char // enumerates players as X or O char data
{
    X = 'X',
    O = 'O'
};

class Game
{
  private:
    array<array<char, len>, len> gameboard; // 2D array of chars representing game board
    Player current;                         // keeps track of current player
    bool gameover;                          // flag for win condition
    int spaces_used;                        // keeps track of how many spaces on board are filled
    bool no_winner;
    array<array<char, len>, len> initialize_gameboard();

  public:
    Game();
    bool check_gameover() { return gameover; };
    void print_gameboard();
    void take_turn();
    void check_for_win();
    void change_player();
    void end_game();
};

#endif // GAME_H