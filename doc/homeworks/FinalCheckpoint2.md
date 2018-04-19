# Final Checkpoint 2
#### 4/18/18

   1. What I Planned On Doing

      I'd still like to get counting cards strategy done. I would also like to begin work on the GUI, even if it won't be in depth as I thought it would be originally.


   2. What I Actually Accomplished

      I successfully implemented Counting Cards using the Zen counting methodologies. This involved continuously keeping track of the count for the table, and the true count, which is adjusted to the number of decks still in play (i.e. changes are more significant when there are less cards in the deck. You can simulate rounds played with counting cards in by running the main terminal app. Note: A progressive betting system has not yet been implemented, so you may notice some extreme loses, but wins in general.
          
      I also did some serious work on implementing the GUI. Over the course of this project, my plan has shifted because of the complexity of the math behind blackjack. Now, it will be an application to play blackjack (and learn basic strategy while doing it), and simulate games with basic strategy and
      counting cards to see the change in advantage it has. The GUI currently allows playing through blackjack. There are some elements missing, but it is a fully functional game, with card images and buttons for actions, etc.

      I realized that much of the Game class was written in order to allow for a playable game (e.g. waiting for user input, printing status to screen, etc.). Between this and the hassle of having the UI (PlayWindow) elements, like buttons, connecting to private Game methods, I decided to modify the
      components Game class to be components of the PlayWindow class itself. That way, I was able to rewrite the round functionality more cleanly. The code in the src directory of the main repo is still the same as previous, and will work as before (the text UI), as I am using that for unit testing,
      confirming that the GUI game is working as expected, and implementing new functionality without dealing with displays yet.

   3. Next Deadline

        a. What I Had Planned

        * At this point, I will finalize all the UI elements. I would like to figure out how to host it or package it as an application. This is also where, time permitting, I will create a gameplay functionality to actually play blackjack with your new knowledge of strategies.

        b. Changes

        * Well, I already implemented the game, but I would like to finalize all the UI elements to show more information (results announcement, blackjacks, etc.), as well as add in some variables the player can choose from. I will also implement the UI to show some kind of information with the simulations of rounds with basic strategy and counting cards. I will need to research more about the betting
        strategies in Zen count, as that is what makes a real difference to the outcomes. I will also package it as an application so it doesn't need to be opened in QT Creator :)


   4. Screenshots

      GUI Menu:
      ![Menu](/doc/screenshots/gui_menu.jpg)

      PlayWindow:
      ![Playwindow](/doc/screenshots/playwindow.jpg)

      Round Start:
      ![setup](/doc/screenshots/gui_setup.jpg)

      Mid-Round:
      ![mid](/doc/screenshots/gui_midturn.jpg)
