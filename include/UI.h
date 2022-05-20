/**
* @author Omar Alsayed
* @date March 2022
*/

#ifndef UI_H
#define UI_H

class UI {
    public:
      UI() {}

      ~UI() {}

      /**
       * Prints the board to the command line
       * @param arr the board
       */
      void print(char arr[][3]);

      /**
       * Gets the X coordinate of the users move
       * @return x-coordinate
       */
      int getX();

      /**
       * Gets the Y coordinate of the users move
       * @return y-coordinate
       */
      int getY();

};

#endif