#include "main.hpp"
bool is_but1(sf::Event event )
{
    bool T_or_F = false;
    if (event.type == sf::Event::MouseButtonPressed)
        T_or_F = true;
    return T_or_F;
}

int main()
{



    std::vector<std::vector<int>> varities; /// варианты ответов для каждой строки (по сути состоит из var1)
    std::vector<int> var1(0); /// варианты ответов (всего 2 ячейки)
    int l = 0;
    std::vector<int> num_str; /// вектор, состоящий из номеров строк (первое число в строке)

    std::string ffff;


    int gg = 1;


    std::ifstream f1;
    std::vector<std::string> stroka;
    std::string strochka;
    std::string chisletsa; /// варианты ответов (на какую строку переход)





    f1.open("game.txt");
    if (!f1.is_open())
        std::cout << "do svidaniya!\n";




    while(!f1.eof()){
        getline(f1, strochka);
        ffff += strochka[0];
        int neww = atoi(ffff.c_str());
        num_str.push_back(neww); /// добавление номера строки
        strochka.erase(strochka.begin(), strochka.begin()+2); /// удаление этого номера из строки (чтобы вывод был без него)
        ffff.clear();
        int p = strochka.length();





        if (isdigit(strochka[p-1])){
            chisletsa += strochka.substr(strochka.length()-3, 3);
            strochka.erase(strochka.end()-3, strochka.end()); /// удаление вариантов ответов из основного текста (чтобы выводился только основной текст)
        }




        for (char s : chisletsa){
            if (isdigit(s)){
                ffff += s;
                int neww1 = atoi(ffff.c_str());
                var1.push_back(neww1); /// загоняем в вектор варианты ответов
                ffff.clear();
            }
        }

        varities.push_back(var1); /// загоняем в основной вектор вариантов ответов
        var1.clear();
        chisletsa.clear();
        stroka.push_back(strochka);
    }


    sf::Font font;
    font.loadFromFile("CyrilicOld.TTF");


    int y = 0;
    sf::Texture texture;
    texture.loadFromFile("background.nkIUY.jpg");
    sf::Sprite sprite(texture, sf::IntRect(0, 0, 1100, 3000)); // отрисовка фона



    sf::Clock clock;

    sf::View view;
    view.setCenter(550, 550);
    view.reset(sf::FloatRect(0, 0, 1100, 1100));


    sf::RectangleShape button1(sf::Vector2f(100, 100)); // левая кнопка
    sf::RectangleShape button2(sf::Vector2f(100, 100));
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100, 1050);
    button1.setFillColor(sf::Color(0, 255, 0));
    button1.setPosition(0, 900);
    button2.setFillColor(sf::Color(255, 0, 0)); // правая кнопка
    button2.setPosition(550, 900);


    bool GameWindow = false;
    std::vector<sf::Text> drawText;
    sf::RenderWindow Menu(sf::VideoMode(1100, 1500), "Menu");
    sf::Texture menu1, menu2, menu_background;

    menu1.loadFromFile("1486486316-arrow-film-movie-play-player-start-video_81236.aZjmZ.png");
    menu2.loadFromFile("stop_stop_exit_270.y0zD3.png");
    menu_background.loadFromFile("a6a580843d72ed64d0d08b839b8d1760.dtDAC.jpg");
    sf::Sprite sprite_menu1(menu1, sf::IntRect(0, 0, 300, 300));
    sf::Sprite sprite_menu2(menu2, sf::IntRect(0, 0, 300, 300));
    sf::Sprite sprite_menu_background(menu_background, sf::IntRect(0,0,1100,1500));

    sf::Event event1;
    sprite_menu1.setPosition(400, 400);
    sprite_menu2.setPosition(400, 900);

    while( Menu.isOpen() ) { /// меню (при нажатии на зеленую кнопку - открытие основного игрового окна, на красную - выход)
        while (Menu.pollEvent(event1)) {

            if (event1.type == sf::Event::Closed)
                Menu.close();
            if (event1.type == sf::Event::MouseButtonPressed &&  sf::IntRect(400, 400, 300, 300).contains(sf::Mouse::getPosition(Menu))) {
                GameWindow = true;
                Menu.close();
            }
            if (event1.type == sf::Event::MouseButtonPressed &&  sf::IntRect(400, 900, 300, 300).contains(sf::Mouse::getPosition(Menu))) {
                Menu.close();

            }




        }
        Menu.draw(sprite_menu_background);
        Menu.draw(sprite_menu1);
        Menu.draw(sprite_menu2);
        Menu.display();

    }

    sf::RenderWindow window(sf::VideoMode(1100, 1100), "Game");
    if (GameWindow)
    {
        while( window.isOpen() ) {


            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time/80;







            while (window.pollEvent(event1)) {
                if (event1.type == sf::Event::Closed)
                    window.close();
                if (event1.type == sf::Event::MouseButtonPressed && sf::IntRect(0, 900, 100, 100).contains(sf::Mouse::getPosition(window)) && varities[l].size() != 0)
/// если нажата зеленая кнопка - переход со сюжету, описанным в "game.txt"
                {
                    press1 = true;



                    gg = varities[l][0];
                    l = varities[l][0];

                    button1.setFillColor(sf::Color(30, 30, 30));



                    std::string str = stroka[gg];
                    sf::Text text1;
                    text1.setFont(font);
                    text1.setString(str);
                    text1.setCharacterSize(50);
                    text1.setPosition(50, 100);

                    window.draw(text1);


/// делаем так, чтобы текст не выходил за пределы экрана и переносился ниже
                    int counter = 1;
                    int n = 1;
                    std::string str1 = str;
                    for (auto ch : str1)
                    {
                        counter += 1;
                        if (counter % 44 == 1){
                            str1.insert(counter-1, "\n");
                            n += 1;
                        }
                    }
                    text1.setString(str1);
                    text1.setPosition(50, 100+y);
                    drawText.push_back(text1);
                    y += n*23;
                    y += 60;
                }



                if (event1.type == sf::Event::MouseButtonPressed && sf::IntRect(550, 900, 100, 100).contains(sf::Mouse::getPosition(window)) && varities[l].size() != 0){

/// если нажата зеленая кнопка - переход со сюжету, описанным в "game.txt"
                    press2 = true;

                    gg = varities[l][1]; //лучше проверить на debug, как это происходит
                    l = varities[l][1];

                    button2.setFillColor(sf::Color(10, 40, 50));


                    std::string str = stroka[gg];
                    sf::Text text1;
                    text1.setFont(font);
                    text1.setString(str);
                    text1.setCharacterSize(50);
                    text1.setPosition(50, 100);

                    window.draw(text1);


/// делаем так, чтобы текст не выходил за пределы экрана и переносился ниже
                    int counter = 1;
                    int n = 1;
                    std::string str1 = str;
                    for (auto ch : str1)
                    {
                        counter += 1;
                        if (counter % 44 == 1){
                            str1.insert(counter-1, "\n");
                            n += 1;
                        }
                    }
                    text1.setString(str1);
                    text1.setPosition(50, 100+y);
                    drawText.push_back(text1);
                    y += n*23;
                    y += 60;
                }

                if (event1.type == sf::Event::MouseButtonReleased && sf::IntRect(0, 900, 100, 100).contains(sf::Mouse::getPosition(window)))
                {
                    button1.setFillColor(sf::Color(0, 255, 0));
                }

                if (event1.type == sf::Event::MouseButtonReleased && sf::IntRect(550, 900, 100, 100).contains(sf::Mouse::getPosition(window)))
                {
                    button2.setFillColor(sf::Color(255, 0, 0));
                }



                window.draw(sprite);
                window.draw(button1);
                window.draw(button2);

                if(event1.mouseWheel.delta==1) { ///скроллинг
                    view.move(0, 1.5*time);
                    button1.move(0, 1.5*time);
                    button2.move(0, 1.5*time);

                }
                if(event1.mouseWheel.delta==-1) {
                    view.move(0, -1.5*time);
                    button1.move(0, -1.5*time);
                    button2.move(0, -1.5*time);

                }



            }
            window.draw(sprite);
            for (sf::Text element : drawText)
                window.draw(element);


            window.draw(button1);
            window.draw(button2);
            window.setView(view);
            window.display();
        }
    }
    return 0;
}