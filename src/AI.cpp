/**
* @author Omar Alsayed
* @date March 2022
*/

#include "AI.h"
#include <vector>
#include <iostream>

int AI::getValue(char arr[][3]) {

    for (int i = 0; i < 3; i++) {
        //checking vertical
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            if (arr[i][0] == 'X') {
                return 10;
            }
            if (arr[i][0] == 'O') {
                return -10;
            }
        }
        //checking horizontal
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            if (arr[0][i] == 'X') {
                return 10;
            }
            if (arr[0][i] == 'O') {
                return -10;
            }
        }
    }
    //checking diagonal
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        if (arr[0][0] == 'X') {
            return 10;
        }
        if (arr[0][0] == 'O') {
            return -10;
        }
    }
    //checking reverse diagonal
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
        if (arr[0][0] == 'X') {
            return 10;
        }
        if (arr[0][2] == 'O') {
            return -10;
        }
    }

    return 0;
}

bool AI::checkTie(char arr[][3]) {
    int tie = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != '_') {
                tie++;
            }
        }
    }
    if (tie == 9) {
        return true;
    }
    return false;
}

int AI::minimax(char arr[][3], bool turn, int alpha, int beta) {

    int val = getValue(arr);

    if (val == 10) {
        return 10;
    }

    if (val == -10) {
        return -10;
    }

    if (checkTie(arr)) {
        return 0;
    }

    //maximizers move
    if (turn) {
        int big = -10000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == '_') {
                    arr[i][j] = 'X';
                    int temp  = minimax(arr, false, alpha, beta);
                    arr[i][j] = '_';
                    big = std::max(temp, big);
                    alpha = std::max(alpha, big);
                    //pruning
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return big;
    }
    //minimizers move
    if (!turn) {
        int small = 10000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] == '_') {
                    arr[i][j] = 'O';
                    int temp = minimax(arr, true, alpha, beta);
                    arr[i][j] = '_';
                    small = std::min(temp, small);
                    beta = std::min(beta, small);
                    //pruning
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return small;
    }
}

std::vector<int> AI::getMove(char arr[][3]) {
    int best = -10000;
    std::vector<int> coords;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == '_') {
                arr[i][j] = 'X';
                int move = minimax(arr, false, -10000, 10000);
                arr[i][j] = '_';

                if (move > best) {
                    coords.clear();
                    coords.push_back(i);
                    coords.push_back(j);
                    best = move;
                }
            }
        }
    }
    return coords;
}