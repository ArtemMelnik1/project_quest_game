#include "main.hpp"

bool is_but1(sf::Event event)
{
    bool T_or_F = false;
    if (event.type == sf::Event::MouseButtonPressed)
        T_or_F = true;
    return T_or_F;
}


bool is_in_mouseRect(sf::Mouse mouse)
{
    bool T_or_F = false;

    auto pos_x = mouse.getPosition().x;
    auto pos_y = mouse.getPosition().y;
    if (pos_x && pos_y < 25000)
        T_or_F = true;
    return T_or_F;
}

bool is_in_mouseRect1(sf::Mouse mouse)
{
    bool T_or_F = false;

    auto pos_x = mouse.getPosition().x;

    if (pos_x  < 25000)
        T_or_F = true;
    return T_or_F;
}

bool is_in_mouseRect2(sf::Mouse mouse)
{
    bool T_or_F = false;


    auto pos_y = mouse.getPosition().y;
    if (pos_y < 25000)
        T_or_F = true;
    return T_or_F;
}