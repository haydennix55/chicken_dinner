#include <iostream>
#include <string>
#include <vector>

#include "Blackjack.h"

int main() {

  Game *g = new Game(6);
  while (true) {
    g->PlayRound();
  }

}
