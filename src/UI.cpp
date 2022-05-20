/**
* @author Omar Alsayed
* @date March 2022
*/

#include "UI.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void UI::print(char arr[][3]) {
    cout << "   1   2   3 " << endl;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << "|";
        for(int j = 0; j < 3; j++) {
            if (arr[i][j] != 'X' && arr[i][j] != 'O') {
                cout << "   |";
            }
            else {
                cout << " " << arr[i][j] << " |";
            }
        }
        cout << "\n";
    }
}

int UI::getX() {
    int x;
    bool b = false;
    while (b == false) {
        cout << "Enter x coordinate\n";
        cin >> x;
        if (x < 1 || x > 3) {
            cout << "Invalid entry. Try again\n";
        }
        else {
            b = true;
        }
    }
    return x-1;
}

int UI::getY() {
    int y;
    bool b = false;
    while (b == false) {
        cout << "Enter y coordinate\n";
        cin >> y;
        if (y < 1 || y > 3) {
            cout << "Invalid entry. Try again\n";
        }
        else {
            b = true;
        }
    }
    return y-1;
}