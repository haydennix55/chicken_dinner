#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>

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

Value increment(Value val) {
    if (val == Value::Two) {
        return Value::Three;
    } else if (val == Value::Three) {
        return Value::Four;
    } else if (val == Value::Four) {
        return Value::Five;
    } else if (val == Value::Five) {
        return Value::Six;
    } else if (val == Value::Six) {
        return Value::Seven;
    } else if (val == Value::Seven) {
        return Value::Eight;
    } else if (val == Value::Eight) {
        return Value::Nine;
    } else if (val == Value::Nine) {
        return Value::Ten;
    } else if (val == Value::Ten) {
        return Value::J;
    } else if (val == Value::J) {
        return Value::Q;
    } else if (val == Value::Q) {
        return Value::K;
    } else {
        return Value::A;
    }
}
//Actions are equal if they are the same strings
bool operator==(Action lhs, Action rhs) {
    if (ActionStringify(lhs) == ActionStringify(rhs)) {
        return true;
    }
    return false;
}

bool operator==(Value lhs, Value rhs) {
    if (ValueStringify(lhs) == ValueStringify(rhs)) {
        return true;
    }
    else {
        return false;
    }
}
// bool operator>=(Value lhs, Value rhs) {
//     if (lhs == Value::A) return true;
//     else if (rhs == Value::A) return false;
//     else return (increment(lhs) >= increment(rhs));
// }
// bool operator<(Value lhs, Value rhs) {
//     return !(lhs >= rhs);
// }
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

        card_val = 0;
        //determine value to increment hand values with
        switch (hand_[i]->get_val()) {

            case Value::Two : card_val = 2;
                            break;
            case Value::Three : card_val = 3;
                            break;
            case Value::Four : card_val = 4;
                            break;
            case Value::Five : card_val = 5;
                            break;
            case Value::Six : card_val = 6;
                            break;
            case Value::Seven : card_val = 7;
                            break;
            case Value::Eight : card_val = 8;
                            break;
            case Value::Nine : card_val = 9;
                            break;
            case Value::Ten : card_val = 10;
                            break;
            case Value::J : card_val = 10;
                            break;
            case Value::Q : card_val = 10;
                            break;
            case Value::K : card_val = 10;
                            break;
            case Value::A : card_val = 11;
                            break;

        }

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
Given the players hand and the showing dealer card, determine what action to
takes. This is currently just a simple cin, but eventually this will be determined
by basic strategy or counting cards.
@return - an int the represents the chosen action
*/
Action Player::MakeChoice() {

    std::string choice;
    while (true){ //until valid choice
      std::cout << "Make your choice: 0 to stay, 1 to hit, 2 to double" << std::endl;
      std::getline (std::cin,choice);
      if (choice == "0") {
          return Action::Stay;
      } else if (choice == "1") {
          return Action::Hit;
      } else if (choice == "2") {
          return Action::Double;
      }
  }
}

Action Player::BasicStrategy(Card* dealer_shown) {
    int hand_val = this->HandVal();
    int dealer_val = ValueIntify(dealer_shown->get_val());
    if (hand_val >= 17) {
        return Action::Stay;
    } else {
        switch(hand_val) {
            case 16 :
            case 15 :
            case 14 :
            case 13 : return (dealer_val >= 7 ? Action::Hit : Action::Stay);
            case 12 : return (dealer_val >= 7 || dealer_val < ValueIntify(Value::Four) ? Action::Hit : Action::Stay);
            case 11 : return (dealer_val == 11 ? Action::Hit : Action::Double);
            case 10 : return (dealer_val >= 10 ? Action::Hit : Action::Double);
            case 9 : return (dealer_val == 2 || dealer_val >= 7 ? Action::Hit : Action::Double);
            default : return Action::Hit;
        }
    }
}
/**
Initializes the deck of given size, and an empty deck for the discard pile. It also does an
initial shuffle, and burns the first card (discards it)
@param decks - number of decks being used for the game
*/
Game::Game(int decks) : deck_(Deck(decks)), discard_(Deck(0)) {
    deck_.Shuffle();
    burn_();
}

//Draw card from deck_ and add to Person's hand
void Game::deal_(Person *p) {
    p->AddToHand(deck_.Draw());
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
        return false;

    } else if (choice == Action::Double) {
        //Double the bet, add a one and only one card to hand, show new hand
        std::cout << "\nYou double. Here's your new hand.\n" ;
        player_.Payout(player_.get_bet_());
        player_.Bet(player_.get_bet_() * 2);
        deal_(&player_);
        DisplayPlayer();
        return true;

    } else {
        //split. This currently isn't implemented and will never occur (see MakeChoice)
        return false;
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
      std::cout << "  -  " << ValueStringify(dealer_.get_hand_()[i]->get_val()) << " of " << SuitStringify(player_.get_hand_()[i]->get_suit()) << std::endl;
  }
  std::cout << std::endl;
}

//Displays only the dealers face up card
void Game::DisplayDealerShown() {
  std::cout << std::endl << "Dealer's showing card:\n--------" << std::endl << std::endl;
  std::cout << "  -  " << ValueStringify(dealer_.get_hand_()[1]->get_val()) << " of " << SuitStringify(player_.get_hand_()[1]->get_suit()) << std::endl << std::endl;
}

//Initialize the bet, the intial deal, and ensure the deck is properly stocked
void Game::SetupRound() {

    //If 4/5s of the deck has been player. This is an approximation of normal shuffling. This may be
    //replaces with a semi-random shuffle card (usually, the dealer inserts it toward the bottom)
    if (deck_.size() < (discard_.size() / 4)) {
      ResetDeck();
    }

    std::cout << std::endl << "----------------------------" << std::endl;
    //when a counting cards comes in, this can change to take a user input, or be determined
    //by the strategy
    player_.Bet(10);

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
Plays an actual round of the game, which encompasses betting, dealing, play, payout, and clearing.
Shuffling and resetting the deck are also implemented if the state is right
*/
void Game::PlayRound() {
    //collect bet, deal, reset deck if necessary
    SetupRound();
    int dealer_score = dealer_.HandVal();
    int player_score = player_.HandVal();

    //TODO: insurance offer if dealer_.get_hand_()[1]->get_val() == Value::A

    //Either dealer, player, or both have blackjack, so round ends
    if (player_score == 21 || dealer_score == 21) {
        //TODO: handle insurance if dealer has blackjack
        AssessResults();
        Clear();
        return;
    }

    //TODO: handle insurance if dealer does not have blackjack

    bool stay = false;
    //Player makes decision until they bust (player_score != 0) or choose a turn ending action (stay or double)
    while (player_score != 0 && !stay) {
        Action choice = player_.MakeChoice(); //will eventually make use of strategy
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
            } else {
                std::cout << "Dealer hits and busts!" << std::endl;
            }
        }
    }

    AssessResults();
    Clear();

}
