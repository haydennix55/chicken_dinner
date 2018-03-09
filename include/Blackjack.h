#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <vector>
#include <string>

enum class Value { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K, A};
enum class Suit { Spades, Diamonds, Clubs, Hearts};
enum class Action { Hit, Stand, Double, Split, Surrender};

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

struct Person {

    public:
        void AddToHand(Card *);
        virtual void Turn();

    protected:
        std::vector<Card*> hand_;
};

//adds chips and betting functionality
struct Player : public Person {

    public:
        Player();
        int Bet(int amount);
        void Turn();

    private:
        int chips_;

};

//turn only needs to include hitting and staying, with different strategy
struct Dealer : public Person {

    public:
        Dealer();
        void Turn();
    private:

};


class Table {

    public:
        Table();
        void PlayRound();

    private:
        Player player_;
        Dealer dealer_;
        Deck deck_;
        Deck discard_;

};
#endif
