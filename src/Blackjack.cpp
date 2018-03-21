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

void Game::deal_(Person *p) {
    p->AddToHand(deck_.Draw());
}

void Game::burn_() {
    discard_.AddToDeck(deck_.Draw());
}

void Game::SetupRound() {

    //TODO: Collect bet

    this->deal_(&player_);
    this->deal_(&dealer_);

    this->deal_(&player_);
    this->deal_(&dealer_);
}

void Game::PlayRound() {
    this->SetupRound();

    //TODO: Check dealer insurance and Blackjack
    //TODO: Check player for Blackjack

    //TODO: Players turn until bust or Stand
    //TODO: If player not busted, dealer turn until busted or > 17

    //TODO: Assess results and payouts
    //TODO: Clear table
}
