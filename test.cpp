#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.hpp"


TEST_CASE("Empty String") {

    sf::Event event;
    event.type =  sf::Event::MouseButtonPressed;

    REQUIRE(is_but1(event ) == false);
}