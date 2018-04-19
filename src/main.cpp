#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Blackjack.h"

int main() {

  //Here is a little taste of the implemented game.
  Game *g = new Game(6);
  std::cout << "Enter 0 to play blackjack yourself (now with a basic strategy suggestion option) or 1 to run 100 simulated games with basic strategy" << std::endl;

  std::string choice;
  while (true) {
      std::getline (std::cin,choice);

      if (choice == "0" || choice == "1") break;
  }

  if (choice == "0") {
      while (true) {
        g->PlayRound(Mode::Player);
      }
  } else {
      for (int i = 0; i < 10000; i++) {
          g->PlayRound(Mode::Basic);
      }
  }

}
