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

TEST_CASE("Emum overload operators", "[enum]") {
    //Note that the card equality operator is tested in the case test_case above
    SECTION("Action equality") {
        Action hit_ = Action::Hit;
        Action stay_ = Action::Stay;
        Action double_ = Action::Double;
        Action split_ = Action::Split;
        Action surrender_ = Action::Surrender;

        REQUIRE(hit_ == Action::Hit);
        REQUIRE(stay_ == Action::Stay);
        REQUIRE(double_ == Action::Double);
        REQUIRE(split_ == Action::Split);
        REQUIRE(surrender_ == Action::Surrender);
    }

    SECTION("Value equality/inequality") {
        Value two = Value::Two;
        Value three = Value::Three;
        Value four = Value::Four;
        Value five = Value::Five;
        Value six = Value::Six;
        Value seven = Value::Seven;
        Value eight = Value::Eight;
        Value nine = Value::Nine;
        Value ten = Value::Ten;
        Value j = Value::J;
        Value q = Value::Q;
        Value k = Value::K;
        Value a = Value::A;

        //equality of literal value
        REQUIRE(two == Value::Two);
        REQUIRE(three == Value::Three);
        REQUIRE(four == Value::Four);
        REQUIRE(five == Value::Five);
        REQUIRE(six == Value::Six);
        REQUIRE(seven == Value::Seven);
        REQUIRE(eight == Value::Eight);
        REQUIRE(nine == Value::Nine);
        REQUIRE(ten == Value::Ten);
        REQUIRE(j == Value::J);
        REQUIRE(q == Value::Q);
        REQUIRE(k == Value::K);
        REQUIRE(a == Value::A);

        //greater than or equal to of intify
        REQUIRE(ValueIntify(a) >= ValueIntify(two));
        REQUIRE(ValueIntify(k) >= ValueIntify(three));
        REQUIRE(ValueIntify(q) >= ValueIntify(four));
        REQUIRE(ValueIntify(j) >= ValueIntify(five));
        REQUIRE_FALSE(ValueIntify(six) >= ValueIntify(ten));
        REQUIRE_FALSE(ValueIntify(seven) >= ValueIntify(nine));
        REQUIRE(ValueIntify(eight) >= ValueIntify(eight));

        //equal to intify
        REQUIRE(ValueIntify(a) == ValueIntify(a));
        REQUIRE(ValueIntify(ten) == ValueIntify(j));
        REQUIRE(ValueIntify(q) == ValueIntify(k));
        REQUIRE(ValueIntify(k) == ValueIntify(ten));

        //less than
        REQUIRE_FALSE(ValueIntify(a) < ValueIntify(two));
        REQUIRE_FALSE(ValueIntify(k) < ValueIntify(three));
        REQUIRE_FALSE(ValueIntify(q) < ValueIntify(four));
        REQUIRE_FALSE(ValueIntify(j) < ValueIntify(five));
        REQUIRE(ValueIntify(six) < ValueIntify(ten));
        REQUIRE(ValueIntify(seven) < ValueIntify(nine));
        REQUIRE_FALSE(ValueIntify(eight) < ValueIntify(eight));
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
        Card three_of_spades(Suit::Spades, Value::Three);
        Card four_of_spades(Suit::Spades, Value::Four);
        Card five_of_spades(Suit::Spades, Value::Five);
        //Card *c = deck.Draw();
        REQUIRE(*deck.Draw() == two_of_spades);
        REQUIRE(*deck.Draw() == three_of_spades);
        REQUIRE(*deck.Draw() == four_of_spades);
        REQUIRE(*deck.Draw() == five_of_spades);
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
    Card *ace_of_diamonds = new Card(Suit::Diamonds, Value::A);

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

    SECTION("Soft Ace check") {
        p.AddToHand(ace_of_spades);
        p.AddToHand(seven_of_hearts);
        REQUIRE(p.HasSoftAce());

        p.AddToHand(ace_of_diamonds);
        REQUIRE(p.HasSoftAce());

        p.AddToHand(ace_of_spades);
        REQUIRE(p.HasSoftAce());

        p.AddToHand(nine_of_hearts);
        REQUIRE_FALSE(p.HasSoftAce());

        p.AddToHand(ace_of_spades);
        REQUIRE_FALSE(p.HasSoftAce());

        p.ClearHand();

        p.AddToHand(ace_of_spades);
        p.AddToHand(five_of_hearts);
        p.AddToHand(queen_of_diamonds);
        p.AddToHand(ace_of_spades);

        REQUIRE_FALSE(p.HasSoftAce());
    }

}

TEST_CASE("Game", "[game]") {

    Game *g2 = new Game(2);
    Game *g6 = new Game(6);

    //based on number of decks - burn card
    REQUIRE(g2->get_deck_().size() == 103);
    REQUIRE(g6->get_deck_().size() == 311);

    //checks burn cards
    REQUIRE(g2->get_discard_().size() == 1);
    REQUIRE(g6->get_discard_().size() == 1);

    //all hands should be empty at start
    REQUIRE(g2->get_player_().get_hand_().size() == 0);
    REQUIRE(g6->get_player_().get_hand_().size() == 0);
    REQUIRE(g2->get_dealer_().get_hand_().size() == 0);
    REQUIRE(g6->get_dealer_().get_hand_().size() == 0);

    /**
    NOTE: All tests playing game were deleted for the time being, as the game currently
    only has one public member function, which requires user input.
    */

}

TEST_CASE("Basic Strategy") {
    Player p;
    Card *two_of_hearts = new Card(Suit::Hearts, Value::Two);
    Card *three_of_hearts = new Card(Suit::Hearts, Value::Three);
    Card *four_of_hearts = new Card(Suit::Hearts, Value::Four);
    Card *five_of_hearts = new Card(Suit::Hearts, Value::Five);
    Card *six_of_hearts = new Card(Suit::Hearts, Value::Six);
    Card *seven_of_hearts = new Card(Suit::Hearts, Value::Seven);
    Card *eight_of_hearts = new Card(Suit::Hearts, Value::Eight);
    Card *nine_of_hearts = new Card(Suit::Hearts, Value::Nine);
    Card *ten_of_hearts = new Card(Suit::Hearts, Value::Ten);
    Card *jack_of_hearts = new Card(Suit::Hearts, Value::J);
    Card *ace_of_diamonds = new Card(Suit::Diamonds, Value::A);

    Card *ace_of_spades = new Card(Suit::Spades, Value::A);
    Card *queen_of_diamonds = new Card(Suit::Diamonds, Value::Q);

    SECTION("Soft Ace Hands") {
        p.AddToHand(ace_of_spades);
        p.AddToHand(two_of_hearts);

        REQUIRE(p.BasicStrategy(five_of_hearts) == Action::Double);
        REQUIRE(p.BasicStrategy(seven_of_hearts) == Action::Hit);

        p.AddToHand(ace_of_spades);
        p.AddToHand(ace_of_spades);

        REQUIRE(p.BasicStrategy(four_of_hearts) == Action::Double);

        p.ClearHand();

        p.AddToHand(ace_of_spades);
        p.AddToHand(seven_of_hearts);

        REQUIRE(p.BasicStrategy(five_of_hearts) == Action::Double);
        REQUIRE(p.BasicStrategy(queen_of_diamonds) == Action::Hit);

        p.ClearHand();

        p.AddToHand(ace_of_spades);
        p.AddToHand(jack_of_hearts);

        REQUIRE(p.BasicStrategy(three_of_hearts) == Action::Stay);
        REQUIRE(p.BasicStrategy(ten_of_hearts) == Action::Stay);


    }

    SECTION("Doubles") {

        p.AddToHand(eight_of_hearts);
        p.AddToHand(eight_of_hearts);
        REQUIRE(p.BasicStrategy(seven_of_hearts) == Action::Split);

        p.ClearHand();

        p.AddToHand(ace_of_spades);
        p.AddToHand(ace_of_spades);
        REQUIRE(p.BasicStrategy(nine_of_hearts) == Action::Split);

        p.ClearHand();
        //
        p.AddToHand(nine_of_hearts);
        p.AddToHand(nine_of_hearts);
        REQUIRE(p.BasicStrategy(seven_of_hearts) == Action::Stay);
        REQUIRE(p.BasicStrategy(eight_of_hearts) == Action::Split);

        p.ClearHand();

        p.AddToHand(five_of_hearts);
        p.AddToHand(five_of_hearts);
        REQUIRE(p.BasicStrategy(four_of_hearts) == Action::Double);
        REQUIRE(p.BasicStrategy(ace_of_spades) == Action::Hit);


    }

    SECTION("Normal Hands") {
        p.AddToHand(four_of_hearts);
        p.AddToHand(six_of_hearts);
        p.AddToHand(five_of_hearts);

        REQUIRE(p.BasicStrategy(six_of_hearts) == Action::Stay);
        REQUIRE(p.BasicStrategy(seven_of_hearts) == Action::Hit);

        p.ClearHand();

        p.AddToHand(ace_of_spades);
        p.AddToHand(five_of_hearts);
        p.AddToHand(queen_of_diamonds);
        p.AddToHand(ace_of_spades);
        std::cout << p.HandVal();

        REQUIRE(p.BasicStrategy(two_of_hearts) == Action::Stay);
        REQUIRE(p.BasicStrategy(ace_of_spades) == Action::Stay);

        p.ClearHand();

        p.AddToHand(two_of_hearts);
        p.AddToHand(seven_of_hearts);

        REQUIRE(p.BasicStrategy(two_of_hearts) == Action::Hit);
        REQUIRE(p.BasicStrategy(six_of_hearts) == Action::Double);
    }
}
