#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <vector>

enum class Value { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K, A};
enum class Suit { Spades, Diamonds, Clubs, Hearts};

std::string SuitStringify(Suit suit);
std::string ValueStringify(Value val);

struct Card {

    public:
        Card(Suit suit, Value val) : suit_(suit), val_(val) {};
        const Value get_val() { return val_; }
        const Suit get_suit() { return suit_; }

    private:
        Value val_;
        Suit suit_;

};

bool operator==(Card lhs, Card rhs);

struct Deck {

    public:
        Deck(int number);
        Card* Draw() { return deck_[0]; };
        int get_size()  { return deck_.size(); };
        Card* get_card(int index) { return deck_[index]; };
    private:
        Card* get_from_cards_(int index) { return &cards_[index]; }
        std::vector<Card*> deck_; //for gameplay
        std::vector<Card> cards_; //for reference from deck_
};

#endif
