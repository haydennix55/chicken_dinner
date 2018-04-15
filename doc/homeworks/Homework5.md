# Homework 4
#### 4/6/18

   1. What I Planned On Doing

      Given that the time between HW4 and final project checkpoint 1 is shorter than I had anticipated, I will revise what I plan on doing. Rather than implement the house edge calculator, which will require many extraneous game variables and a GUI or user interaction, I plan on finishing the big picture part of my original plan for the checkpoint: Basic Strategy. I will have an algorithm written to determine how to act according to probability and have the application able to play rounds by itself using basic strategy.


   2. What I Actually Accomplished

      I successfully implemented Basic Strategy. I incorporated it into the players game to offer suggestions to the player. I also added functionality to be able to simulate games played with basic strategy. This will be important once I have implemented card counting to compare the long term results of either. I did not implement it the way I had hoped. I had hoped to build and algorithm to determine the basic strategy decisions based solely on probability. After many hours of researching, it turns out the basic strategy rules were determined from long term simulations to determine the choice with the highest win probability. Even given the small amount of initial conditions for the player and outcomes, there are 4.562 x 10^192 possible combinations of hands (for example: if you have 14, there is stay, 10 possible doubles, a split that creates two new hands, and 10 possible hits that could lead to even more). The best shot would be an evolutionary algorithm, but even still, it would be very difficult to compute exact probabilities. Instead, I implemented the choices based on the classic chart. It lead me to several difficulties, including determined if a hand is soft (using an Ace as an 11), which had to be implemented.

      What I Didn't Do: The probability algorithm (see above).

   3. Next Deadline

        a. What I Had Planned

        * For this checkpoint, I would like to have the card counting strategy implemented. This will include variable betting and will require added functions to the house edge calculator and the game functionality.

        b. Changes

        * I'd still like to get counting cards strategy done. I would also like to begin work on the GUI, even if it won't be in depth as I thought it would be originally.

   4. Screenshots

      Basic Strategy Suggestions:
      ![advice](/doc/screenshots/basicadvice.jpg)

      100 Rounds w/ Basic Strategy:
      ![rounds](/doc/screenshots/100rounds.jpg)
