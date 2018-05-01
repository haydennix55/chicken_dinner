#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <cmath>

#include "Blackjack.h"

//Convert enums to strings of their names
std::string SuitStringify(Suit suit) {
    if (suit == Suit::Spades){
        return "Spades";
    } else if (suit == Suit::Diamonds){
        return "Diamonds";
    } else if (suit == Suit::Clubs){
        return "Clubs";
    } else {
        return "Hearts";
    }
}
std::string ValueStringify(Value val) {
    switch (val) {
        case Value::Two : return "Two";
                        break;
        case Value::Three : return "Three";
                        break;
        case Value::Four : return "Four";
                        break;
        case Value::Five : return "Five";
                        break;
        case Value::Six : return "Six";
                        break;
        case Value::Seven : return "Seven";
                        break;
        case Value::Eight : return "Eight";
                        break;
        case Value::Nine : return "Nine";
                        break;
        case Value::Ten : return "Ten";
                        break;
        case Value::J : return "J";
                        break;
        case Value::Q : return "Q";
                        break;
        case Value::K : return "K";
                        break;
        case Value::A : return "A";
                        break;
    }
}
std::string ActionStringify(Action act) {
    switch (act) {
        case Action::Hit : return "Hit";
                        break;
        case Action::Stay : return "Stay";
                        break;
        case Action::Double : return "Double";
                        break;
        case Action::Split : return "Split";
                        break;
        case Action::Surrender :  return "Surrender";
                        break;
    }
}

//Convert card values to their game values (11 for ace)
int ValueIntify(Value val) {
    switch (val) {
        case Value::Two : return 2;
        case Value::Three : return 3;
        case Value::Four : return 4;
        case Value::Five : return 5;
        case Value::Six : return 6;
        case Value::Seven : return 7;
        case Value::Eight : return 8;
        case Value::Nine : return 9;
        case Value::Ten :
        case Value::J :
        case Value::Q :
        case Value::K : return 10;
        case Value::A : return 11;
    }
}

//Cards are equal if they have the same Suit and Value
bool operator==(Card lhs, Card rhs) {
    if (lhs.get_val() == rhs.get_val() && lhs.get_suit() == rhs.get_suit()){
        return true;
    }
    return false;
}

//Actions are equal if they are the same strings
bool operator==(Action lhs, Action rhs) {
    if (ActionStringify(lhs) == ActionStringify(rhs)) {
        return true;
    }
    return false;
}

//Build a vector of instances of all 52 cards
CardFactory::CardFactory() {
    std::vector<Suit> suits {Suit::Spades, Suit::Diamonds, Suit::Clubs, Suit::Hearts};

    std::vector<Value> values {Value::Two, Value::Three, Value::Four, Value::Five,
        Value::Six, Value::Seven, Value::Eight, Value::Nine, Value::Ten, Value::J,
        Value::Q, Value::K, Value::A};

    //create vector of the 52 different possible cards
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            cards_.push_back(Card(suits[i],values[j]));
        }
    }
}

//Return a reference to a card in the CardFactory (flyweight)
Card* CardFactory::get_card(int index) {
  Card *c = &cards_[index];
  return c;
}

/**
Populates deck vector with references to Cards in the CardFactory
@param number -  the number of decks the game will use
*/
Deck::Deck(int number) {
    //create a deck of n * 52 references to the cards
    for (int deck = 0; deck < number; deck++){
        for (int i = 0; i < 52; i++){
            deck_.push_back(factory_.get_card(i));
        }
    }
}

//Return top card in deck and erase from deck
Card* Deck::Draw() {
    Card *c = deck_[0];
    deck_.erase(deck_.begin());
    return c;
}

//Mixes the cards in a decks card* vector
void Deck::Shuffle() {
    std::vector<Card*> newDeck;
    int deck_size = deck_.size();
    srand((unsigned)time(0)); //used so that random number changes
    int random_index;

    for (int i = 0; i < deck_size; i++){
        random_index = rand() % deck_.size(); //random number between 0 and current deck size
        newDeck.push_back(deck_[ random_index ]); //add random choice to new deck
        deck_.erase(deck_.begin() + random_index); //erase random choice from old deck
    }

    deck_ = newDeck;
}

/**
Determine the best value for a given hand of cards. The best value would be
the highest value that is less than 21.
@return - the best score or 0 if no possible score is less than 21
*/
int Person::HandVal() {
    std::vector<int> hand_values; //potential values
    hand_values.push_back(0);
    int card_val;

    //for every card in hand, update potential value
    for (int i = 0; i < hand_.size(); i++) {

        card_val = ValueIntify(hand_[i]->get_val());

        int temp = hand_values.size();

        //if ace, duplicate the elements of the vector as they need to be
        //considered with both +11 and +1
        if (card_val == 11){

            for (int i = 0; i < temp; i++){
                hand_values.push_back(hand_values[i]);
            }
            //increment the first half of values with 1, the rest will increment by 11 later
            for (int i = temp; i < hand_values.size(); i++){
                hand_values[i]++;
            }

        }

        //increment all possible hand values by card value
        for (int i = 0; i < temp; i++) {
            hand_values[i] += card_val;
        }


    }

    int max = 0;
    //find highest score thats under 21, or 0 if none
    for (int i = 0; i < hand_values.size(); i++){
        if (hand_values[i] > max && hand_values[i] <= 21){
            max = hand_values[i];
        }
    }

    return max;

}

/**
Determines if there is an Ace in the player's hand that is being used for a value
of 11. Technically, a hand is soft when you can hit without the risk of going over 21,
but strategy is only different for soft aces vs. hard aces
@return -  true if it has a soft ace, false otherwise
*/
bool Person::HasSoftAce() {
    int ace_count = 0; //number of aces in hand
    int size = hand_.size();
    std::vector<Card*> temp_hand = hand_;
    //remove all aces from hand and increment ace count
    for (int i = 0; i < size;) {
        if (temp_hand[i]->get_val() == Value::A) {
            ace_count++;
            temp_hand.erase(temp_hand.begin() + i);
            size--;
        } else {
            i++;
        }
    }
    //determine value of hand without aces
    int temp_hand_val = 0;
    for (int i = 0; i < temp_hand.size(); i++) {
        temp_hand_val += ValueIntify(temp_hand[i]->get_val());
    }
    //if the val of the full hand is the value of the hand without aces
    //plus the number of aces in the full hand, that means all aces are
    //being used with a value of 1, and not soft
    if (HandVal() == (temp_hand_val + ace_count)) return false;

    return true;

}

/**
Given the players hand and the showing dealer card, determine what action to
takes. This is currently just a simple cin, but eventually this will be determined
by basic strategy or counting cards.
@return - an int the represents the chosen action
*/
Action Player::MakeChoice(Card* dealer_shown) {

    std::string choice;
    while (true){ //until valid choice
      std::cout << "Make your choice: 0 to stay, 1 to hit, 2 to double, 3 to split, or 4 to see what basic strategy would say" << std::endl;
      std::getline (std::cin,choice);
      if (choice == "0") {
          return Action::Stay;
      } else if (choice == "1") {
          return Action::Hit;
      } else if (choice == "2") {
          return Action::Double;
      } else if (choice == "3") {
          if (hand_.size() == 2 && ValueIntify(hand_[0]->get_val()) == ValueIntify(hand_[1]->get_val())) {
              return Action::Split;
          } else {
              std::cout << "You can only split on a hand of two cards with the same value" << std::endl;
          }
      } else if (choice == "4") {
          std::cout << "Basic Strategy would say to " << ActionStringify(this->BasicStrategy(dealer_shown)) << "." << std::endl;
      }
  }
}

/**
Given the dealers face up card and the players hand, return the action
with the lowest statistical probablity of losing. These choices were determined
with simulation.
@return - the best action a player should take given the game state
*/
Action Player::BasicStrategy(Card* dealer_shown) {
    int hand_val = this->HandVal(); //playable value of players hand
    int dealer_val = ValueIntify(dealer_shown->get_val()); //int value of dealers face up card

    //If the player hand is doubles
    if (hand_.size() == 2 && ValueIntify(hand_[0]->get_val()) == ValueIntify(hand_[1]->get_val())) {
        if (hand_[0]->get_val() == Value::A || hand_[0]->get_val() == Value::Eight) {
            return Action::Split;
        } else if (ValueIntify(hand_[0]->get_val()) == 10) {
            return Action::Stay;
        } else {
            switch(ValueIntify(hand_[0]->get_val())) {
                case 9: return (dealer_val <= 9 && dealer_val != 7 ? Action::Split : Action::Stay);
                case 7:
                case 3:
                case 2: return (dealer_val <= 7 ? Action::Split : Action::Hit);
                case 6: return (dealer_val <= 6 ? Action::Split : Action::Hit);
                case 5: return (dealer_val <= 9 ? Action::Double : Action::Hit);
                case 4: return (dealer_val == 5 || dealer_val == 6 ? Action::Split : Action::Hit);
                //this stops a warning for non-void function exit, but should never occur
                default: throw std::runtime_error("Unreachable code in basic strat");
            }
        }
    } else if (this->HasSoftAce() ) { //hands with a soft ace can make more aggressive plays
        switch(hand_val) {
            case 21:
            case 20:
            case 19: return Action::Stay;
            case 18: if (dealer_val >= 9) {
                return Action::Hit;
            } else {
                if (dealer_val >= 3 && dealer_val < 7) return Action::Double;
                return Action::Stay;
            }
            case 17: return (dealer_val >= 3 && dealer_val < 7 ? Action::Double : Action::Hit);
            case 16:
            case 15: return (dealer_val >= 4 && dealer_val < 7 ? Action::Double : Action::Hit);
            case 14:
            case 13: return (dealer_val >= 5 && dealer_val < 7 ? Action::Double : Action::Hit);
            //this stops a warning for non-void function exit, but should never occur
            default: throw std::runtime_error("Unreachable code in basic strat");
        }
    } else if (hand_val >= 17) { //any other hands over 17
        return Action::Stay;
    } else {
        switch(hand_val) { //all other hands
            case 16 :
            case 15 :
            case 14 :
            case 13 : return (dealer_val >= 7 ? Action::Hit : Action::Stay);
            case 12 : return (dealer_val >= 7 || dealer_val < ValueIntify(Value::Four) ? Action::Hit : Action::Stay);
            case 11 : return (dealer_val == 11 ? Action::Hit : Action::Double);
            case 10 : return (dealer_val >= 10 ? Action::Hit : Action::Double);
            case 9 : return (dealer_val == 2 || dealer_val >= 7 ? Action::Hit : Action::Double);
            default : return Action::Hit; //all hands under 9
        }
    }

}

/**
Initializes the deck of given size, and an empty deck for the discard pile. It also does an
initial shuffle, and burns the first card (discards it)
@param decks - number of decks being used for the game
*/
Game::Game(int decks) : deck_(Deck(decks)), discard_(Deck(0)), num_of_decks_(decks) {
    deck_.Shuffle();
    burn_();
}

//Draw card from deck_ and add to Person's hand
void Game::deal_(Person *p) {
    Card *c = deck_.Draw();
    UpdateTrueCount(c);
    p->AddToHand(c);
}

//Draw a card from the deck and add it to the discard pile
void Game::burn_() {
    discard_.AddToDeck(deck_.Draw());
}

/**
Takes action chosen and performs said Action
@param choice - int representing the action
@return - true if its an action that definitively ends players turn, false otherwise
*/
bool Game::DoTurn(Action choice) {

    if (choice == Action::Stay) {

        std::cout << "\nYou chose to stay.\n" ;
        return true;

    } else if (choice == Action::Hit) {
        //add card to hand and display new hand
        std::cout << "\nYou chose to hit. Here's your new hand.\n" ;
        deal_(&player_);
        DisplayPlayer();
        DisplayDealerShown();
        return false;

    } else if (choice == Action::Double) {
        //Double the bet, add a one and only one card to hand, show new hand
        std::cout << "\nYou double. Here's your new hand.\n" ;
        player_.Payout(player_.get_bet_());
        player_.Bet(player_.get_bet_() * 2);
        deal_(&player_);
        DisplayPlayer();
        DisplayDealerShown();
        return true;

    } else {
        //split. This currently isn't implemented and will never occur (see MakeChoice)
        std::cout << "You split" << std::endl;
        return true;
    }
}

/**
Using information from the game state, including player score, dealer score, and
their hand sizes, determines win, lose, tie, or blackjack and pays out chips accordingly
*/
void Game::AssessResults() {
    int dealer_score = dealer_.HandVal();
    int player_score = player_.HandVal();
    int bet = player_.get_bet_();

    //Blackjack, pays 3/2
    if (player_score == 21 && dealer_score != 21) {
        if (player_.get_hand_().size() == 2) {
            player_.Payout(bet * 2.5);
            std::cout << "WINNER WINNER CHICKEN DINNER!" << std::endl;
            return;
        }
    }
    if (player_score == 0) {
        std::cout << "You busted..." << std::endl;
    } else {
        if (player_score > dealer_score) { //win
            std::cout << "You win." << std::endl;
            player_.Payout(bet * 2);
        } else if (player_score == dealer_score) { //tie
            std::cout << "Its a Push." << std::endl;
            player_.Payout(bet);
        } else {  //loss
            if (dealer_score == 21 && dealer_.get_hand_().size() == 2){
                std::cout << "Dealer has Blackjack!" << std::endl;
            }
            std::cout << "You lose." << std::endl;
            //Because the dealer does not currently keep track of chips,
            //no action is required. (Withdrawn from player when bet)
        }
    }
}

//Resets the game after a round
void Game::Clear() {
    std::vector<Card*> player_hand = player_.get_hand_();
    std::vector<Card*> dealer_hand = dealer_.get_hand_();

    //move players hand to discard
    for (int i = 0; i < player_hand.size(); i++) {
        discard_.AddToDeck(player_hand[i]);
    }

    //move dealers hand to discard
    for (int i = 0; i < dealer_hand.size(); i++) {
        discard_.AddToDeck(dealer_hand[i]);
    }

    //clear last rounds data
    player_.ClearHand();
    dealer_.ClearHand();
    player_.Bet(0);

    //These were used to ensure the deck was decrementing corrently, and that it resets properly
    // std::cout << "Deck size: " << deck_.size() << std::endl;
    // std::cout << "Discard size: " << discard_.size() << std::endl;
    std::cout << "Player Chips: " << player_.get_chips_() << std::endl;
    std::cout << "True Count: " << get_true_count_() << std::endl;
    std::cout << std::endl << "----------------------------" << std::endl;


}

//Replaces all discarded cards to deck
void Game::ResetDeck() {
    for (int i = 0; i < discard_.size(); i++) {
      deck_.AddToDeck(discard_.get_card(i));
    }
    discard_.ClearDeck();
    deck_.Shuffle();
    burn_();
    count_ = 0;
    true_count_ = 0;
}

/**
The following three functions create a simple text UI. These will be unnecessary when
GUI is created
*/

//Print out Players hand
void Game::DisplayPlayer() {
    //this is a placeholder for now for the UI
    std::cout << std::endl << "Player's hand:\n--------" << std::endl << std::endl;
    for (int i = 0; i < player_.get_hand_().size(); i++) {
        std::cout << "  -  " << ValueStringify(player_.get_hand_()[i]->get_val()) << " of " << SuitStringify(player_.get_hand_()[i]->get_suit()) << std::endl;
    }
    std::cout << std::endl;
}

//Prints out Dealers hand
void Game::DisplayDealer() {
  std::cout << std::endl << "Dealer's hand:\n-------- " << std::endl << std::endl;
  for (int i = 0; i < dealer_.get_hand_().size(); i++) {
      std::cout << "  -  " << ValueStringify(dealer_.get_hand_()[i]->get_val()) << " of " << SuitStringify(dealer_.get_hand_()[i]->get_suit()) << std::endl;
  }
  std::cout << std::endl;
}

//Displays only the dealers face up card
void Game::DisplayDealerShown() {
  std::cout << std::endl << "Dealer's showing card:\n--------" << std::endl << std::endl;
  std::cout << "  -  " << ValueStringify(dealer_.get_hand_()[1]->get_val()) << " of " << SuitStringify(dealer_.get_hand_()[1]->get_suit()) << std::endl << std::endl;
}

//Initialize the bet, the intial deal, and ensure the deck is properly stocked
void Game::SetupRound(Mode mode, int min_bet) {

    //If 4/5s of the deck has been player. This is an approximation of normal shuffling. This may be
    //replaces with a semi-random shuffle card (usually, the dealer inserts it toward the bottom)
    if (deck_.size() < (discard_.size() / 4)) {
      ResetDeck();
    }

    std::cout << std::endl << "----------------------------" << std::endl;

    //Variable betting for counting cards. If the true count is -1 or less, don't play.
    //Otherwise, bet your minimum stable bet * (true count + 1)
    if (mode == Mode::Counting) {
        int multiplier = (round(true_count_) + 1);
        if (multiplier <= 1) {
           player_.Bet(0);
        } else {
            player_.Bet(multiplier * min_bet);
        }
    } else {
      //if not playing with card counting
      player_.Bet(min_bet);
    }


    std::cout << "Player's bet: " << player_.get_bet_() << std::endl;

    //Deal hands alternating to player and dealer
    deal_(&player_);
    deal_(&dealer_);

    deal_(&player_);
    deal_(&dealer_);

    //Show player hand and dealer face up card
    DisplayPlayer();
    DisplayDealerShown();

}

/**
 * @brief Updates the true count value of the game using the Zen count methodology
 * @param c is the last drawn card, used to update the count and therefore, the true count
 */
void Game::UpdateTrueCount(Card* c) {
    switch (ValueIntify(c->get_val())) {
        case 2:
        case 3:
        case 7: count_++;
                break;
        case 4:
        case 5:
        case 6: count_ += 2;
                break;
        case 11: count_ -= 1;
                break;
        case 10: count_ -= 2;
                break;
        default:
                break;
    }

    float remaining_decks = ((float)deck_.size() / (num_of_decks_ * 52)) * num_of_decks_;

    remaining_decks = round(remaining_decks * 2) / 2;

    true_count_ = count_ / remaining_decks;

}
/**
Plays an actual round of the game, which encompasses betting, dealing, play, payout, and clearing.
Shuffling and resetting the deck are also implemented if the state is right
*/
void Game::PlayRound(Mode mode, int min_bet) {
    //collect bet, deal, reset deck if necessary
    SetupRound(mode, min_bet);
    int dealer_score = dealer_.HandVal();
    int player_score = player_.HandVal();

    //Either dealer, player, or both have blackjack, so round ends
    if (player_score == 21 || dealer_score == 21) {
        //TODO: handle insurance if dealer has blackjack
        AssessResults();
        Clear();
        return;
    }

    bool stay = false;
    //Player makes decision until they bust (player_score != 0) or choose a turn ending action (stay or double)

    Action choice;
    while (player_score != 0 && !stay) {
        if (mode == Mode::Basic || mode == Mode::Counting) choice = player_.BasicStrategy(dealer_.get_hand_()[1]);
        else choice = player_.MakeChoice(dealer_.get_hand_()[1]);
        if (choice == Action::Split) {
            std::cout << "Split has not yet been implemented" << std::endl; //eventually this will be split functionality
        }
        stay = DoTurn(choice);  //true if turn ending, false if otherwise
        player_score = player_.HandVal();
    }

    //Reveal Dealer's hand
    DisplayDealer();

    //If already busted, go to AssessResults
    if (player_score == 0) {
          AssessResults();
          Clear();
          return;
    } else {
        //dealer must hit until they have 17 or they bust. This does not take
        //into account soft 17, which may be implemented later
        while (dealer_score < 17 && dealer_score != 0) {
            deal_(&dealer_);
            dealer_score = dealer_.HandVal();
            if (dealer_score != 0){
                std::cout << "Dealer hits and now has: " << dealer_score << std::endl;
                DisplayDealer();
            } else {
                std::cout << "Dealer hits and draws a " << ValueStringify(dealer_.get_hand_()[dealer_.get_hand_().size() - 1]->get_val())
                << " of " <<  SuitStringify(dealer_.get_hand_()[dealer_.get_hand_().size() - 1]->get_suit()) << " and busts!" << std::endl;
            }
        }
    }

    AssessResults();
    Clear();

}

