/**
* @author Omar Alsayed
* @date March 2022
*/

#ifndef AI_H
#define AI_H
#include <vector>

/**
 * AI that uses the minimax algorithm with alpha-beta pruning to 
 * play tic tac toe
 */
class AI {
    public:
      AI() {}

      ~AI() {}

      /**
       * Uses the minimax algorithm to evaluate a move
       * @param arr the tic tac toe board
       * @param turn bool true if its AI players turn, false if otherwise
       * @param alpha the alpha value for pruning
       * @param beta the beta value for pruning 
       * @return the score assigned to the move
       */
      int minimax(char arr[][3], bool turn, int alpha, int beta);
      
      /**
       * Finds the optimal move
       * @param arr the tic tac toe board
       * @return vector of ints containing the coordinate of the best move
       */
      std::vector<int> getMove(char arr[][3]);
      
      /**
       * Evaluates the board and returns the static score
       * @param arr the board
       * @return the score
       */
      int getValue(char arr[][3]);

      /**
       * Checks for a tie
       * @param arr the tic tac toe board
       * @return bool true if there is a tie, false if not
       */
      bool checkTie(char arr[][3]);
};


#endif