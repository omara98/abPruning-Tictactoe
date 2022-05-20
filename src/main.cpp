/**
* @author Omar Alsayed
* @date March 2022
*/

#include <iostream>
#include <vector>
#include <string>
#include "AI.h"
#include "UI.h"
#include "Game.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
  Game* g = new Game();
  g->gameLoop();
  delete g;
  return 0;
}