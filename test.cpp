#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.hpp"


TEST_CASE("First") {

    sf::Event event;
    event.type =  sf::Event::MouseButtonPressed;

    REQUIRE(is_but1(event) == true);
}

TEST_CASE("Second") {

    sf::Mouse  mouse;

    REQUIRE(is_in_mouseRect(mouse) == true);
}

TEST_CASE("Third") {

    sf::Mouse  mouse;

    REQUIRE(is_in_mouseRect1(mouse) == true);
}

TEST_CASE("Fourth") {

    sf::Mouse  mouse;

    REQUIRE(is_in_mouseRect2(mouse) == true);
}