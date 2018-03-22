#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

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
        Card* get_card(int index);

    private:
        std::vector<Card> cards_;
};

struct Deck {

    public:
        Deck(int number);
        int size()  { return deck_.size(); };
        Card* get_card(int index) { return deck_[index]; };
        void AddToDeck(Card *c) { deck_.push_back(c); };

        Card* Draw();
        void Shuffle();
    private:
        std::vector<Card*> deck_; //for gameplay
        CardFactory factory_;
};

struct Person {

    public:
        Person() {};
        ~Person() {};
        std::vector<Card*> get_hand_() { return hand_; };

        void AddToHand(Card *c) { hand_.push_back(c); };
        int HandVal();


    protected:
        std::vector<Card*> hand_;
        int hand_count_;
};

//adds chips and betting functionality
struct Player : public Person {

    public:
        Player() : Person() {};
        int Bet(int amount);
        int MakeChoice();

    private:
        int chips_;

};

//turn only needs to include hitting and staying, with different strategy
struct Dealer : public Person {

    public:
        Dealer() : Person() {};
    private:

};

class Game {

    public:
        Game(int decks);
        ~Game() {std::cout << "game deleted" << std::endl;};
        Player get_player_() { return player_; };
        Dealer get_dealer_() { return dealer_; };
        Deck get_deck_() { return deck_; };
        Deck get_discard_() { return discard_; };

        void DisplayTablePlayer();
        void SetupRound();
        void PlayRound();
        void doTurn();
        void doDealerTurn();

    private:
        Player player_;
        Dealer dealer_;
        Deck deck_;
        Deck discard_;
        void deal_(Person *p);
        void burn_();


};


#endif
