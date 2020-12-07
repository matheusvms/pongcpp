//
// Created by mathe on 6-12-2020.
//

#ifndef PONGCPP_GAME_H
#define PONGCPP_GAME_H

#endif //PONGCPP_GAME_H

#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerPaddle.h"
class Game
{
public:
    static void Start();
private:
    static bool IsExiting();
    static void GameLoop();

    static void ShowSplashScreen();
    static void ShowMenu();
    enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };
    static GameState _gameState;
    static sf::RenderWindow _mainWindow;
    static PlayerPaddle _player1;
};