//
// Created by sofia on 06/12/2020.
//

#ifndef PONGCPP_MAINMENU_H
#define PONGCPP_MAINMENU_H

#endif //PONGCPP_MAINMENU_H
//
// Created by sofia on 06/12/2020.
//

#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>
class MainMenu
{
public:
    enum MenuResult { Nothing, Exit, Play };
    MenuResult Show(sf::RenderWindow& window);
private:
    MenuResult GetMenuResponse(sf::RenderWindow& window);
};