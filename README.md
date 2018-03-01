# chicken_dinner [![Build Status](https://travis-ci.org/haydennix55/chicken_dinner.svg?branch=master)](https://travis-ci.org/haydennix55/chicken_dinner)

_Blackjack, on its surface, is a simple game. The goal: get as close to 21 as possible
without going over._ 

Simple enough, right? In reality, there is a lot more to consider. The number of decks, payouts, doubling rules, shuffling methods, and many other factors contribute to the house edge, the minimum advantage the dealer has over the player. These advantages are calculated assuming play by basic strategy, a guide for moves based solely on probability. Unfortunately, even in the best case scenario and strict basic strategy, the house holds a slight advantage. This means no matter how skilled or lucky you think you are, the house will win eventually. However, the minor house advantage can be reversed using the difficult technique known as counting cards (which although casinos frown upon, is legal). The best counters can supplement the probabilities that determine basic strategy based on the contents of the discard pile to give the player a slight (0.5 - 1 %) advantage.

This application is a simulation of both strategies: basic and counting cards. Here, you can see how they work in action, as well as how they (and other game variables) impact the house edge. With proper play and a little luck, maybe you can hear those magic words: [__WINNER WINNER CHICKEN DINNER!__](http://modernnotion.com/say-winner-winner-chicken-dinner/)

## Getting Started

These instructions will allow you to see where I am at. These will be updated as I build this project, and will include information about running the application as a user or downloading for development.

### Prerequisites

The code is currently tested on Linux and Mac OS X. On these operating systems, there should be no prereqs to build and run the source code. Because the GUI has not been packaged and deployed, it will require Qt Creator to build and run.

### Downloading and Running Application

This section is currently not applicable. This will be filled when there is a packaged application.

### Development

Start by cloning the repository to your local machine.

* __Download, Build, and Run Source Code__
     
   * Use the following commands to build and run:
     
      * `make` - generates executable `bin/app` using `main.cpp` and `src/Blackjack.cpp`, and places object files in `build/`. Use `./bin/app` to run. 
           
      * `make test` - generates executable `bin/test/` using `test.cpp` and the object files in `build/`. If they are not created, it will first run `make`. Use `./bin/test` to run the test suite.
      
      * `make clean` - cleans the directory by deleting the `build/` directory and both `bin/app` and `bin/test` executables.

* __Run Catch Test Suite__

   * See above about command `make test`

* __Build and__

   * Open Qt Creator
   TODO: FINISH

## Tools

* [Catch2](https://github.com/catchorg/Catch2) - A modern, C++-native, header-only, test framework 
* [TravisCI](https://travis-ci.org) - A hosted, distributed continuous integration service
* [Qt](https://www.qt.io/) - A cross-platform software development for embedded & desktop


## License

TODO: Apache Liscence

