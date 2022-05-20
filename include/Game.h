/**
* @author Omar Alsayed
* @date March 2022
*/

#ifndef GAME_H
#define GAME_H
#include "UI.h"
#include "AI.h"

class Game {
    public:
     
     /**
      * The constructor, initializes the tic tac toe board
      */
     Game() {
        arr[0][0] = '_';
        arr[0][1] = '_';
        arr[0][2] = '_';
        arr[1][0] = '_';
        arr[1][1] = '_';
        arr[1][2] = '_';
        arr[2][0] = '_';
        arr[2][1] = '_';
        arr[2][2] = '_';
     }
     ~Game() {}

     /**
      * Checks for a winner after a move is made
      * @param x x-coordinate of move 
      * @param y y-coordinate of move
      * @param c the character to be checked (either X or O)
      * @return bool true if winner found, false if otherwise
      */
     bool winCheck(int x, int y, char c);

     /**
      * The game loop
      */
     void gameLoop();

     /**
      * Places the given character at the specified coordinates
      * @param x x-coordinate of move
      * @param y y-coordinate of move
      * @param c the character to be placed (either X or O)
      */
     void makeMove(int x, int y, char c);

    private:
     AI* ai;
     UI* ui;
     char arr[3][3];
};

#endif