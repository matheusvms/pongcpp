//
// Created by mathe on 6-12-2020.
//

#include "SplashScreen.h"
#include "StdAfx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
    sf::Image image;

    sf::Texture texture;
    if(texture.loadFromFile("SplashScreen.png") != true)
    {
        return;
    }
    sf::Sprite sprite(texture);
    renderWindow.draw(sprite);
    renderWindow.display();
    sf::Event event;
    while(true)
    {
        while(renderWindow.pollEvent(event))
        {
            if(event.type == sf::Event::EventType::KeyPressed
               || event.type == sf::Event::EventType::MouseButtonPressed
               || event.type == sf::Event::EventType::Closed )
            {
                return;
            }
        }
    }
}