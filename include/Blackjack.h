#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

enum class Value { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K, A};
enum class Suit { Hearts, Diamonds, Clubs, Spades};

struct Card {

    public:
        Card(Suit suit, Value val) : suit_(suit), val_(val) {};
        Value get_val() { return val_; }
        Suit get_suit() { return suit_; }

    private:
        Value val_;
        Suit suit_;

};

#endif
