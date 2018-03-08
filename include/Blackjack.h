#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <vector>
#include <string>

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

struct CardFactory {

    public:
        CardFactory();
        Card* get_card(int index) { return &cards_[index]; }

    private:
        std::vector<Card> cards_;
};

struct Deck {

    public:
        Deck(int number);
        int size()  { return deck_.size(); };
        Card* get_card(int index) { return deck_[index]; };

        Card* Draw();
        void Shuffle();
    private:
        std::vector<Card*> deck_; //for gameplay
        CardFactory factory_;
};

#endif
