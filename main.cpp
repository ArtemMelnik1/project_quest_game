#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

void menu(sf::RenderWindow &  window) {
    sf::Texture menu1, menu2, menu_background;
    menu1.loadFromFile("1486486316-arrow-film-movie-play-player-start-video_81236.aZjmZ.png");
    menu2.loadFromFile("stop_stop_exit_270.y0zD3.png");
    menu_background.loadFromFile("a6a580843d72ed64d0d08b839b8d1760.dtDAC.jpg");
    sf::Sprite sprite_menu1(menu1, sf::IntRect(0, 0, 300, 300));
    sf::Sprite sprite_menu2(menu2, sf::IntRect(0, 0, 300, 300));
    sf::Sprite sprite_menu_background(menu_background, sf::IntRect(0,0,1100,1500));
    bool ismenu = true;
    sf::Event event1;
    sprite_menu1.setPosition(400, 400);
    sprite_menu2.setPosition(400, 900);



    while (ismenu) {
        while (window.pollEvent(event1)) {
            sf::Vector2i mouse1 = sf::Mouse::getPosition(window);
            if (event1.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (sprite_menu1.getGlobalBounds().contains(mouse1.x, mouse1.y)) {
                    ismenu = false;
                }
                if (sprite_menu2.getGlobalBounds().contains(mouse1.x, mouse1.y)) {
                    window.close();
                    ismenu = false;
                }
            }
        }
        window.draw(sprite_menu_background);
        window.draw(sprite_menu1);
        window.draw(sprite_menu2);
        window.display();
    }
}



int main() {
    sf::RenderWindow window(sf::VideoMode(1100, 1500), "100 steps");
    menu(window);




    sf::View view;
    view.reset(sf::FloatRect(0, 0, 1100, 1500));



    sf::Texture texture;
    texture.loadFromFile("background.jpg");
    sf::Sprite sprite(texture, sf::IntRect(0, 0, 1100, 1500));





    sf::RectangleShape button1(sf::Vector2f(550, 250));
    sf::RectangleShape button2(sf::Vector2f(550, 250));
    button1.setFillColor(sf::Color(0, 255, 0));
    button1.setPosition(0, 1250);
    button2.setFillColor(sf::Color(255, 0, 0));
    button2.setPosition(550, 1250);




    string a;
    string input("game.txt");
    ifstream file1;
    file1.open(input);
    getline(file1, a);




    float y = 0;




    while( window.isOpen() ) {
        sf::Event event;


        sf::Font font;
        font.loadFromFile("CyrilicOld.TTF");
        sf::Text text;
        text.setFont(font);
        text.setString(a);
        text.setCharacterSize(50);
        text.setPosition(50, 50);
        text.setColor(sf::Color(0, 255, 0));








        sf::Text text1;
        text1.setFont(font);
        text1.setString("game");
        text1.setCharacterSize(50);
        text1.setPosition(50, 100);
        text1.setColor(sf::Color(0, 255, 0));




        sf::View view;
        view.reset(sf::FloatRect(0, 0, 1100, 1500));



        while (window.pollEvent(event)) {



            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (button1.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button1.setFillColor(sf::Color(0, 0, 255));
                    window.draw(text1);


                }
                if (button2.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button2.setFillColor(sf::Color(30, 90, 40));
                }
            }


            if (event.type == sf::Event::MouseButtonReleased) {
                if (button1.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button1.setFillColor(sf::Color(0, 255, 0));
                }
                if (button2.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button2.setFillColor(sf::Color(255, 0, 0));
                }
            }




            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                view.move(0, y);
                button1.setPosition(0, 1250 + y);
                button2.setPosition(550, 1250 + y);
                y += 100;
            }


            window.setView(view);
            window.clear();
            window.draw(sprite);
            window.draw(button1);
            window.draw(button2);
            window.draw(text);
            window.display();



        }



    }



//   vector<int> numbers;
    //  string a, b;
    //ifstream input("game.txt");
    // try{
    //   if (!input.is_open()){
    //     throw "This file does not exist";
    //}
    //}
    //catch (const char* exception){
    //    cerr<< "Error: " << exception << endl;
    //}
    //while (input.is_open()){
    //  getline(input, a, ' ');
    //getline(input, b);
    //}
}