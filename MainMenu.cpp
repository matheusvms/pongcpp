//
// Created by sofia on 06/12/2020.
//

#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

    //Load menu image from file
    sf::Texture texture;
    texture.loadFromFile("mainmenu.png");
    sf::Sprite sprite(texture);

    //Setup clickable regions

    //Play menu item coordinates

    window.draw(sprite);
    window.display();

    return GetMenuResponse(window);
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event menuEvent;

    while(true)
    {

        while(window.pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    return Play;
                }
            }
            if (menuEvent.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    return Exit;
                }
            }
        }
    }
}
