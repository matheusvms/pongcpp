//
// Created by mathe on 6-12-2020.
//

#ifndef PONGCPP_GAME_H
#define PONGCPP_GAME_H

#endif //PONGCPP_GAME_H
#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
class Game
{
public:
    static void Start();
private:
    static bool IsExiting();
    static void GameLoop();
    enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };

    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
};