#ifndef _BLACKJACK_H_
#define _BLACKJACK_H_

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

enum class Value { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K, A};
enum class Suit { Spades, Diamonds, Clubs, Hearts};
enum class Action { Hit, Stay, Double, Split, Surrender};

//Convert enums to strings of their names
std::string SuitStringify(Suit suit);
std::string ValueStringify(Value val);
std::string ActionStringify(Action act);
int ValueIntify(Value val);

//Card with Suit and Value fields
struct Card {

    public:
        Card(Suit suit, Value val) : suit_(suit), val_(val) {};
        const Value get_val() { return val_; }
        const Suit get_suit() { return suit_; }

    private:
        Value val_;
        Suit suit_;

};

//Cards are equal if they have the same Suit and Value
bool operator==(Card lhs, Card rhs);
Value increment(Value val);
//Actions are equal if they are the same strings
bool operator==(Action lhs, Action rhs);


//Contains a vector of the 52 cards to be referenced to make decks
struct CardFactory {

    public:
        CardFactory();
        Card* get_card(int index);

    private:
        std::vector<Card> cards_;
};

/** Deck
This contains a CardFactory, a vector of references to the cards in the
factor, and methods to manipulate the deck.
*/
struct Deck {

    public:
        Deck(int number);
        int size()  { return deck_.size(); };
        Card* get_card(int index) { return deck_[index]; };

        void AddToDeck(Card *c) { deck_.push_back(c); };
        void ClearDeck() { deck_.clear(); };
        Card* Draw();
        void Shuffle();

    private:
        std::vector<Card*> deck_; //for gameplay
        CardFactory factory_;
};

/** Person
Base class for both dealer and player, with hand, a vector of Card*, and
related methods
*/
struct Person {

    public:
        Person() {};
        std::vector<Card*> get_hand_() { return hand_; };

        void AddToHand(Card *c) { hand_.push_back(c); };
        void ClearHand() { hand_.clear(); };
        int HandVal();
        bool HasSoftAce();

    protected:
        std::vector<Card*> hand_;
};

//Derived class from Person that adds betting, making game decisions, and chips
struct Player : public Person {

    public:
        Player() : Person() {};
        int get_bet_() { return bet_; }
        int get_chips_() { return chips_; }

        void Bet(int amount) { bet_ = amount;
                              chips_ -= amount; };
        void Payout(int amount) { chips_ += amount; };
        Action MakeChoice();
        Action BasicStrategy(Card* dealer_shown);
    private:
        int chips_ = 1000;
        int bet_ = 0;

};

//Derived class from Person, which does not have any player functionality
struct Dealer : public Person {
    public:
        Dealer() : Person() {};
    private:
};

/** Game
This creates the entire table enviornment and allows rounds to be played. Like
a blackjack table, it has a dealer, player, deck, discard, and methods to play rounds
*/
class Game {

    public:
        Game(int decks);
        ~Game() {std::cout << "game deleted" << std::endl;};
        Player get_player_() { return player_; };
        Dealer get_dealer_() { return dealer_; };
        Deck get_deck_() { return deck_; };
        Deck get_discard_() { return discard_; };

        void PlayRound();

    private:
        Player player_;
        Dealer dealer_;
        Deck deck_;
        Deck discard_;
        void deal_(Person *p);
        void burn_();
        void DisplayPlayer();
        void DisplayDealerShown();
        void DisplayDealer();
        void ResetDeck();
        void SetupRound();


        bool DoTurn(Action choice);
        void AssessResults();
        void Clear();



};


#endif
