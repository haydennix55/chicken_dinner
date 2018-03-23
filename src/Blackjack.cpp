#include "Blackjack.h"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <tuple>

bool operator==(Card lhs, Card rhs) {
    if (lhs.get_val() == rhs.get_val() && lhs.get_suit() == rhs.get_suit()){
        return true;
    }
    return false;
}

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

Card* CardFactory::get_card(int index) {
  Card *c = &cards_[index];
  return c;
}

Deck::Deck(int number) {
    //create a deck of n * 52 references to the cards
    for (int deck = 0; deck < number; deck++){
        for (int i = 0; i < 52; i++){
            deck_.push_back(factory_.get_card(i));
        }
    }
}

Card* Deck::Draw() {
    Card *c = deck_[0];
    deck_.erase(deck_.begin());
    return c;
}

void Deck::Shuffle() {
    std::vector<Card*> newDeck;
    int deck_size = deck_.size();
    srand((unsigned)time(0));
    int random_index;

    for (int i = 0; i < deck_size; i++){
        random_index = rand() % deck_.size();
        newDeck.push_back(deck_[ random_index ]);
        deck_.erase(deck_.begin() + random_index);
    }

    deck_ = newDeck;
}

void Deck::ClearDeck() {
  deck_.clear();
}

int Person::HandVal() {
    std::vector<int> hand_values;
    hand_values.push_back(0);
    int card_val;

    for (int i = 0; i < hand_.size(); i++) {

        card_val = 0;
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

        if (card_val == 11){

            for (int i = 0; i < temp; i++){
                hand_values.push_back(hand_values[i]);
            }
            for (int i = temp; i < hand_values.size(); i++){
                hand_values[i]++;
            }

        }

        for (int i = 0; i < temp; i++) {
            hand_values[i] += card_val;
        }


    }

    int max = 0;

    for (int i = 0; i < hand_values.size(); i++){
        if (hand_values[i] > max && hand_values[i] <= 21){
            max = hand_values[i];
        }
    }

    return max;

}

void Person::ClearHand() {
  hand_.clear();
}

int Player::MakeChoice() {

    //this will eventually have strategy methods, but for now, always stay
    std::string choice;
    while (true){
      std::cout << "Make your choice: 0 to stay, 1 to hit, 2 to double" << std::endl;
      std::getline (std::cin,choice);
      if (choice == "0" || choice == "1" || choice == "2") {
        return stoi(choice);
      }
    }

}

Game::Game(int decks) : deck_(Deck(decks)), discard_(Deck(0)) {
    deck_.Shuffle();
    this->burn_();
}

void Game::deal_(Person *p) {
    p->AddToHand(deck_.Draw());
}

void Game::burn_() {
    discard_.AddToDeck(deck_.Draw());
}

bool Game::DoTurn(int choice) {

  if (choice == 0) {
    std::cout << "You stay\n" ;
    return true;
  }else if (choice == 1) {
    std::cout << "You hit\n" ;
    deal_(&player_);
    DisplayPlayer();
    return false;
  } else if (choice == 2) {
    std::cout << "You double\n" ;
    player_.Payout(player_.get_bet_());
    player_.Bet(player_.get_bet_() * 2);
    deal_(&player_);
    DisplayPlayer();
    return true;
  } else {
    //split
    return false;
  }
}

void Game::AssessResults() {
  int dealer_score = dealer_.HandVal();
  int player_score = player_.HandVal();
  int bet = player_.get_bet_();

  if (player_score == 21 && dealer_score != 21) {
    if (player_.get_hand_().size() == 2) {
      player_.Payout(bet * 2.5);
      std::cout << "nice blackjack" << std::endl;
    }
  } else if (player_score == 0) {
    std::cout << "You busted" << std::endl;
  }
  else {
    if (player_score > dealer_score) {
      std::cout << "You win" << std::endl;
      player_.Payout(bet * 2);
    } else if (player_score == dealer_score) {
      std::cout << "push" << std::endl;
      player_.Payout(bet);
    } else {
    std::cout << "you lose" << std::endl;
  }
    //else its a loss, which currently has no payout as the dealer doesn't
    //have a total amount
  }
}

void Game::Clear() {
  std::vector<Card*> player_hand = player_.get_hand_();
  std::vector<Card*> dealer_hand = dealer_.get_hand_();

  for (int i = 0; i < player_hand.size(); i++) {
    discard_.AddToDeck(player_hand[i]);
  }

  for (int i = 0; i < dealer_hand.size(); i++) {
    discard_.AddToDeck(dealer_hand[i]);
  }
  player_.ClearHand();
  dealer_.ClearHand();
  player_.Bet(0);

  std::cout << "Game reset" << std::endl;
  std::cout << "Player hand size: " << player_.get_hand_().size() << std::endl;
  std::cout << "Dealer hand size: " << dealer_.get_hand_().size() << std::endl;
  std::cout << "Deck size: " << deck_.size() << std::endl;
  std::cout << "Discard size: " << discard_.size() << std::endl;
  std::cout << "Player chips: " << player_.get_chips_() << std::endl;
  std::cout << std::endl << "----------------------------" << std::endl;


}

void Game::ResetDeck() {
    for (int i = 0; i < discard_.size(); i++) {
      deck_.AddToDeck(discard_.get_card(i));
    }
    discard_.ClearDeck();
}

void Game::DisplayPlayer() {
    //this is a placeholder for now for the UI
    std::cout << std::endl << "Players hand: " << std::endl << std::endl;
    for (int i = 0; i < player_.get_hand_().size(); i++) {
        std::cout << ValueStringify(player_.get_hand_()[i]->get_val()) << " of " << SuitStringify(player_.get_hand_()[i]->get_suit()) << std::endl;
    }
    std::cout << std::endl;
}

void Game::DisplayDealer() {
  std::cout << std::endl << "Dealers hand: " << std::endl << std::endl;
  for (int i = 0; i < dealer_.get_hand_().size(); i++) {
      std::cout << ValueStringify(dealer_.get_hand_()[i]->get_val()) << " of " << SuitStringify(player_.get_hand_()[i]->get_suit()) << std::endl;
  }
  std::cout << std::endl;
}

void Game::DisplayDealerShown() {
  std::cout << std::endl << "Dealers showing card: " << std::endl << std::endl;
  std::cout << ValueStringify(dealer_.get_hand_()[1]->get_val()) << " of " << SuitStringify(player_.get_hand_()[1]->get_suit()) << std::endl << std::endl;
}

void Game::SetupRound() {

    if (deck_.size() < (discard_.size() / 4)) {
      ResetDeck();
    }
    //when a counting cards comes in, this can change
    std::cout << std::endl << "----------------------------" << std::endl;
    player_.Bet(10);

    std::cout << "Player bets: " << player_.get_bet_() << std::endl;

    deck_.Shuffle();

    deal_(&player_);
    deal_(&dealer_);

    deal_(&player_);
    deal_(&dealer_);

    DisplayPlayer();
    DisplayDealerShown();

}

void Game::PlayRound() {
    SetupRound();
    int dealer_score = dealer_.HandVal();
    int player_score = player_.HandVal();

    //TODO: Display state of table

    if (dealer_.get_hand_()[1]->get_val() == Value::A) {
        //TODO: insurance offer
    }

    if (player_score == 21 || dealer_score == 21) {
        //TODO: handle insurance
        AssessResults();
        Clear();
        return;
    }

    //TODO: handle insurance

    bool stay = false;
    while (player_score != 0 && !stay) {

        int choice = player_.MakeChoice(); //strategy
        stay = DoTurn(choice);
        player_score = player_.HandVal();
        std::cout << player_score << std::endl;

    }

    DisplayDealer();

    if (player_score == 0) {
      AssessResults();
      Clear();
      return;
    } else {
      while (dealer_score < 17 && dealer_score != 0) {
            deal_(&dealer_);
            dealer_score = dealer_.HandVal();
            std::cout << "Dealer hits and now has: " << dealer_score << std::endl;
      }
    }

    AssessResults();
    Clear();

}
