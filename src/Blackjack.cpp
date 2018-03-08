#include "Blackjack.h"
#include <string>
#include <iostream>
#include <vector>

bool operator==(Card lhs, Card rhs){
    if (lhs.get_val() == rhs.get_val() && lhs.get_suit() == rhs.get_suit()){
        return true;
    }
    return false;
}

std::string SuitStringify(Suit suit){
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

std::string ValueStringify(Value val){
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

Deck::Deck(int number){
    //create a deck of n * 52 references to the cards
    for (int deck = 0; deck < number; deck++){
        for (int i = 0; i < 52; i++){
            deck_.push_back(factory_.get_card(i));
        }
    }
}
