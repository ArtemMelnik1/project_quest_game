#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;



// функция для создания меню(начальное окно), при нажатии на кнопку play меню закрывается и включается игра, при нажатии на красную кнопку, игра закрывается
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




    sf:: Clock clock;







    sf::Texture texture;
    texture.loadFromFile("background.nkIUY.jpg");
    sf::Sprite sprite(texture, sf::IntRect(0, 0, 1100, 3000)); // отрисовка фона





    sf::RectangleShape button1(sf::Vector2f(550, 250)); // левая кнопка
    sf::RectangleShape button2(sf::Vector2f(550, 250));
    button1.setFillColor(sf::Color(0, 255, 0));
    button1.setPosition(0, 1250);
    button2.setFillColor(sf::Color(255, 0, 0)); // правая кнопка
    button2.setPosition(550, 1250);




    string a;
    string input("game.txt");
    ifstream file1;
    file1.open(input);
    getline(file1, a);





    float x = 550;
    float y = 0;





    while( window.isOpen() ) {
        sf::Event event;



        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 80;


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
        text1.setColor(sf::Color(0, 255, 0)); // текст, который должен выводиться при нажатии кнопки (не выводится)




        sf::View view;
        view.setCenter(550, 750);
        view.reset(sf::FloatRect(0, 0, 1100, 1500));



        while (window.pollEvent(event)) {







            window.setView(view);
            window.clear();





            sf::Vector2i localPosition = sf::Mouse::getPosition(window);



            sf::Vector2i mouse = sf::Mouse::getPosition(window);
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (button1.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button1.setFillColor(sf::Color(0, 0, 255));
                    window.draw(text1); // если координаты мыши находятся внутри левой нижней кнопки и она нажата, то кнопка меняет цвет + почему-то на экране не отрисовывается текст


                }
                if (button2.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button2.setFillColor(sf::Color(30, 90, 40)); // если нажата правая нижняя кнопка, то она также меняет цвет
                }
            }


            if (event.type == sf::Event::MouseButtonReleased) {
                if (button1.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button1.setFillColor(sf::Color(0, 255, 0));
                }
                if (button2.getGlobalBounds().contains(mouse.x, mouse.y)) {
                    button2.setFillColor(sf::Color(255, 0, 0));
                }
            } // если кнопка мыша не нажата, то цвет кнопки возвращается в изначальное (для эффекта нажатия кнопки)



            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                button1.setPosition(0, 1250 + y);
                button2.setPosition(550, 1250 + y);
                view.move(0, y);
                y += 50;
                cout << x << " " << y << " "; // для проверки координат скроллинга карты через кнопку (оказалось сложнее)
            }



            if (localPosition.y > 1400) { view.move(550, y);  button1.setPosition(0, 1250 + y);
                button2.setPosition(550, 1250 + y); view.setCenter(550, 750 + y); y += 5;}//нижний край - вниз
            if (localPosition.y < 3) {  view.move(550, -y);  button1.setPosition(0, 1250 - y);
                button2.setPosition(550, 1250 - y); view.setCenter(550, 750 - y); y += 5; } // если мышь находится внизу или наверху, происходит скроллинг фона и кнопок (с этим тоже есть трудности)



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