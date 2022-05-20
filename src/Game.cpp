/**
* @author Omar Alsayed
* @date March 2022
*/

#include "Game.h"
#include "UI.h"
#include <iostream>

bool Game::winCheck(int x, int y, char c) {
    int hori = 0;
    int vert = 0;
    int diag = 0;
    int rdiag = 0;
    int tie = 0;
    bool b = false;

    for (int i = 0; i < 3; i++) {
        if (arr[x][i] == c) {
            vert++;
        }
        if (arr[i][y] == c) {
            hori++;
        }
        if (arr[i][i] == c) {
            diag++;
        }
        if (arr[i][3-i+1] == c) {
            rdiag++;
        }
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != '_') {
                tie++;
            }
        }
    }
    if (hori == 3 || vert == 3 || diag == 3 || rdiag == 3) {
        b = true;
        std::cout << c << " wins!" << std::endl;
    }
    else if (tie == 9) {
        b = true;
        std::cout << "Its a tie!" << std::endl;
    }

    return b;
}

void Game::gameLoop() {
    ui = new UI();
    ai = new AI();
    ui->print(arr);
    bool win = false;
    int turn = 0;
    int x;
    int y;
    while (win != true) {
        //AI's turn
        if (turn == 0) {
            std::vector<int> coords = ai->getMove(arr);
            x = coords.at(0);
            y = coords.at(1);
            makeMove(x, y, 'X');
            ui->print(arr);
            win = winCheck(x, y, 'X');
            turn = 1;
        }
        //Players turn
        else {
            bool b = false;
            while (b == false) {
                x = ui->getX();
                y = ui->getY();
                if (arr[x][y] != '_') {
                    std::cout << "Oops, that spot is taken. Please try again.\n";
                }
                else {
                    b = true;
                }
            }
            makeMove(x, y, 'O');
            ui->print(arr);
            win = winCheck(x, y, 'O');
            turn = 0;
        }
    }
    delete ai;
    delete ui;
}

void Game::makeMove(int x, int y, char c) {
    arr[x][y] = c;
}