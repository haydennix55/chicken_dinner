# Final Checkpoint 2
#### 5/2/18

   1. What I Planned On Doing

     I would like to finalize all the UI elements to show more information (results announcement, blackjacks, etc.), as well as add in some variables the player can choose from. I will also implement the UI to show some kind of information with the simulations of rounds with basic strategy and counting cards. I will need to research more about the betting
     strategies in Zen count, as that is what makes a real difference to the outcomes. I will also package it as an application so it doesn't need to be opened in QT Creator :)


   2. What I Actually Accomplished

      I did everything I set out to do and more. I cleaned up the gameplay UI and added the results announcements. I added some displays to show other in game information (count, true count etc.) I also added game variables that accept user input including number of decks, the dealer soft 17 policy, and the bet for the next round. This will hopefully help users practice counting cards as they can vary their bet accordingly and vary the game using the most common casino variables. I added the simulation pages, which allows users to run games with 2500 rounds of play using either counting cards or basic strategy. This too allows the user to select the number of decks and the soft 17 policy, as well as the minimum bet (which is the amount bet in the basic strategy and the value used to determine bets in counting cards). The results are then displayed in a plot graph, where each point represents the total player chips after a single round. This allows the user to see the general trends of gains/losses over time, and the volatility of different aggressions of play. Finally, I packaged the application up so it no longer required QtCreator to play. Overall, I accomplished even more than I had expected to this checkpoint, and have a fully functional application! Awesome!

   3. Next Deadline

      No more deadlines. :)


   4. Screenshots

      GUI Menu:
      ![Menu](/doc/screenshots/menuFinal.jpg)

      Gameplay GUI:
      ![Playwindow](/doc/screenshots/gameplayFinal.jpg)

      SimulationGUI:
      ![sim](/doc/screenshots/simFinal.jpg)
