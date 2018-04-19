#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Blackjack.h"

int main() {

  //Here is a little taste of the implemented game.
  Game *g = new Game(6);
  std::cout << "Enter 0 to play blackjack yourself (now with a basic strategy suggestion option) or 1 to run 1000 simulated games with counting cards strategy" << std::endl;

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
      for (int i = 0; i < 1000; i++) {
          g->PlayRound(Mode::Basic);
      }
      std::cout << "NOTE: While on average, you should see wins, you may notice some massive losses. This is because we simply bet our base bet multiplied by the current true count.\n This does have potential for huge losses. For example, if the count stays high for many rounds and you still fall victim to the 49 percent chance the dealer has to win, you could lose big.\n This will change when a progressive betting system is implemented" << std::endl;
  }

}
