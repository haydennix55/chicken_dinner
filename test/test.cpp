#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Blackjack.h"

TEST_CASE("Card struct","[card]"){
    SECTION("can be created successfully and accessed"){
        Card c(Suit::Spades, Value::A);
        REQUIRE(c.get_val() == Value::A);
        REQUIRE(c.get_suit() == Suit::Spades);

    }


}
