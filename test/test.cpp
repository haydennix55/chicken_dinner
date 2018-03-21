#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Blackjack.h"
#include <string>

TEST_CASE("Card struct","[card]"){
    Card *a = new Card(Suit::Spades, Value::A);
    SECTION("can be created successfully and accessed"){
        REQUIRE(a->get_val() == Value::A);
        REQUIRE(a->get_suit() == Suit::Spades);
    }
    SECTION("has working overloaded equality"){
        Card base(Suit::Spades, Value::A);
        Card same(Suit::Spades, Value::A);
        Card different(Suit::Diamonds, Value::Q);
        Card wrong_suit(Suit::Clubs, Value::A);
        Card wrong_val(Suit::Spades, Value::Four);

        REQUIRE(base == same);
        REQUIRE_FALSE(base == different);
        REQUIRE_FALSE(base == wrong_suit);
        REQUIRE_FALSE(base == wrong_val);
    }
    SECTION("has working overloaded equality with dereferenced pointers"){
        Card *same = new Card(Suit::Spades, Value::A);
        Card *different = new Card(Suit::Diamonds, Value::Q);
        Card *wrong_suit = new Card(Suit::Clubs, Value::A);
        Card *wrong_val = new Card(Suit::Spades, Value::Four);

        REQUIRE(*a == *same);
        REQUIRE_FALSE(*a == *different);
        REQUIRE_FALSE(*a == *wrong_suit);
        REQUIRE_FALSE(*a == *wrong_val);
    }
}

TEST_CASE("Stringify returns expected strings", "[Stringify]"){

    SECTION("using SuitStringify"){
        REQUIRE("Hearts" == SuitStringify(Suit::Hearts));
        REQUIRE("Spades" == SuitStringify(Suit::Spades));
        REQUIRE("Diamonds" == SuitStringify(Suit::Diamonds));
        REQUIRE("Clubs" == SuitStringify(Suit::Clubs));
    }

    SECTION("using ValueStringify"){
        REQUIRE("Two" == ValueStringify(Value::Two));
        REQUIRE("Three" == ValueStringify(Value::Three));
        REQUIRE("Four" == ValueStringify(Value::Four));
        REQUIRE("Five" == ValueStringify(Value::Five));
        REQUIRE("Six" == ValueStringify(Value::Six));
        REQUIRE("Seven" == ValueStringify(Value::Seven));
        REQUIRE("Eight" == ValueStringify(Value::Eight));
        REQUIRE("Nine" == ValueStringify(Value::Nine));
        REQUIRE("Ten" == ValueStringify(Value::Ten));
        REQUIRE("J" == ValueStringify(Value::J));
        REQUIRE("Q" == ValueStringify(Value::Q));
        REQUIRE("K" == ValueStringify(Value::K));
        REQUIRE("A" == ValueStringify(Value::A));
    }

}

TEST_CASE("Deck","[deck]"){
    Deck deck(1);
    Deck deck6(6);
    SECTION("cstr creates vector of size 52 for one deck"){
        Deck deck2(2);
        REQUIRE(deck.size() == 52);
        REQUIRE(deck2.size() == 104);
        REQUIRE(deck6.size() == 312);
    }
    SECTION("draw function returns correct first card"){
        Card two_of_spades(Suit::Spades, Value::Two);
        Card *c = deck.Draw();
        REQUIRE(*(c) == two_of_spades);
    }
    SECTION("get_card returns correct cards"){
        Card two_of_spades(Suit::Spades,Value::Two);
        REQUIRE(*(deck.get_card(0)) == two_of_spades);
        REQUIRE(*(deck6.get_card(0)) == two_of_spades);

        Card ace_of_hearts(Suit::Hearts, Value::A);
        REQUIRE(*(deck.get_card(51)) == ace_of_hearts);
        REQUIRE(*(deck6.get_card(51)) == ace_of_hearts);

        Card queen_of_diamonds(Suit::Diamonds, Value::Q);
        REQUIRE(*(deck6.get_card(23)) == queen_of_diamonds);
        REQUIRE(*(deck6.get_card(75)) == queen_of_diamonds);
        REQUIRE(*(deck6.get_card(127)) == queen_of_diamonds);
        REQUIRE(*(deck6.get_card(179)) == queen_of_diamonds);
        REQUIRE(*(deck6.get_card(231)) == queen_of_diamonds);
        REQUIRE(*(deck6.get_card(283)) == queen_of_diamonds);

    }

}

TEST_CASE("shuffle method", "[shuffle]") {
    Deck deck(6);
    Deck oldDeck = deck;
    deck.Shuffle();
    bool different = false;

    for (int i = 0; i < deck.size(); i++){
        if (deck.get_card(i) != oldDeck.get_card(i)) {
            different = true;
            break;
        }
    }

    REQUIRE(deck.size() == oldDeck.size());
    REQUIRE(different);
}

TEST_CASE("Person's derived classes", "[person]") {
    Person p;
    Dealer d;

    REQUIRE(p.get_hand_().size() == 0);
    REQUIRE(d.get_hand_().size() == 0);

    Card *c = new Card(Suit::Diamonds, Value::Q);
    p.AddToHand(c);
    d.AddToHand(c);

    REQUIRE(p.get_hand_().size() == 1);
    REQUIRE(d.get_hand_().size() == 1);

    /* Must add more test cases when turns are implemented */

}

TEST_CASE("HandVal in Person base class", "[handval]") {
    Person p;
    Dealer d;

    Card *two_of_hearts = new Card(Suit::Hearts, Value::Two);
    Card *three_of_hearts = new Card(Suit::Hearts, Value::Three);
    Card *four_of_hearts = new Card(Suit::Hearts, Value::Four);
    Card *five_of_hearts = new Card(Suit::Hearts, Value::Five);
    Card *six_of_hearts = new Card(Suit::Hearts, Value::Six);
    Card *seven_of_hearts = new Card(Suit::Hearts, Value::Seven);
    Card *eight_of_hearts = new Card(Suit::Hearts, Value::Eight);
    Card *nine_of_hearts = new Card(Suit::Hearts, Value::Nine);

    Card *ace_of_spades = new Card(Suit::Spades, Value::A);
    Card *queen_of_diamonds = new Card(Suit::Diamonds, Value::Q);

    SECTION("determines value of single card hand (base case)") {
        p.AddToHand(two_of_hearts);
        d.AddToHand(two_of_hearts);

        REQUIRE(p.HandVal() == 2);
        REQUIRE(d.HandVal() == 2);
    }

    SECTION("determines value of two simple cards less than") {
        p.AddToHand(two_of_hearts);
        d.AddToHand(two_of_hearts);
        p.AddToHand(three_of_hearts);
        d.AddToHand(three_of_hearts);

        REQUIRE(p.HandVal() == 5);
        REQUIRE(d.HandVal() == 5);

        Person p2;
        p2.AddToHand(queen_of_diamonds);
        p2.AddToHand(three_of_hearts);

        REQUIRE(p2.HandVal() ==  13);

    }

    SECTION("returns best value for two card hand with one ace < 21"){
        p.AddToHand(three_of_hearts);
        p.AddToHand(ace_of_spades);

        REQUIRE(p.HandVal() == 14);
    }

    SECTION("returns best value for two card hand with one ace = 21"){
        p.AddToHand(queen_of_diamonds);
        p.AddToHand(ace_of_spades);

        REQUIRE(p.HandVal() == 21);
    }

    SECTION("returns best value for two card hand with two aces"){
        p.AddToHand(ace_of_spades);
        p.AddToHand(ace_of_spades);

        REQUIRE(p.HandVal() == 12);
    }

    SECTION("returns best value for n cards or 0 if not <= 21"){
        p.AddToHand(two_of_hearts);
        p.AddToHand(four_of_hearts);

        REQUIRE(p.HandVal() == 6);

        p.AddToHand(nine_of_hearts);

        REQUIRE(p.HandVal() == 15);

        p.AddToHand(five_of_hearts);

        REQUIRE(p.HandVal() == 20);

        p.AddToHand(two_of_hearts);

        REQUIRE(p.HandVal() == 0);
    }

    SECTION("returns best value for n cards with aces or 0 if not any <= 21"){
        p.AddToHand(ace_of_spades);
        p.AddToHand(ace_of_spades);

        REQUIRE(p.HandVal() == 12);

        p.AddToHand(queen_of_diamonds);

        REQUIRE(p.HandVal() == 12);

        p.AddToHand(nine_of_hearts);

        REQUIRE(p.HandVal() == 21);

        p.AddToHand(ace_of_spades);

        REQUIRE(p.HandVal() == 0);

    }

    //TODO: Returns value of n card hand with aces
    //TODO: Returns 0 if no hand values are LEQ 21



}

TEST_CASE("Game class", "[game]") {
    Game g2(2);
    Game g6(6);

    REQUIRE(g2.get_deck_().size() == 104);
    REQUIRE(g6.get_deck_().size() == 312);

    REQUIRE(g2.get_discard_().size() == 0);
    REQUIRE(g6.get_discard_().size() == 0);

    REQUIRE(g2.get_player_().get_hand_().size() == 0);
    REQUIRE(g6.get_player_().get_hand_().size() == 0);
    REQUIRE(g2.get_dealer_().get_hand_().size() == 0);
    REQUIRE(g6.get_dealer_().get_hand_().size() == 0);

    g2.PlayRound();
    g6.PlayRound();

    REQUIRE(g2.get_deck_().size() == 100);
    REQUIRE(g6.get_deck_().size() == 308);

    REQUIRE(g2.get_player_().get_hand_().size() == 2);
    REQUIRE(g6.get_player_().get_hand_().size() == 2);
    REQUIRE(g2.get_dealer_().get_hand_().size() == 2);
    REQUIRE(g6.get_dealer_().get_hand_().size() == 2);


}
