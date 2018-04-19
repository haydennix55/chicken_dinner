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

