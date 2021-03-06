//
// Created by mathe on 6-12-2020.
//
#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
void Game::Start(void)
{
    if(_gameState != Uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(600,450,32),"Pang!");

    _player1.Load("paddle.png");
    _player1.SetPosition((1024/2)-45,400);
    _gameState= Game::ShowingSplash;
    while(!IsExiting())
    {
        GameLoop();
    }
    _mainWindow.close();
}
bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}
void Game::GameLoop()
{
    switch(_gameState)
    {
        case Game::ShowingMenu:
        {
            ShowMenu();
            break;
        }
        case Game::ShowingSplash:
        {
            ShowSplashScreen();
            break;
        }
        case Game::Playing:
        {
            sf::Event currentEvent;
            while(_mainWindow.pollEvent(currentEvent))
            {
                _mainWindow.clear(sf::Color(0,0,0));
                _player1.Draw(_mainWindow);
                _mainWindow.display();

                if(currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;
                if(currentEvent.type == sf::Event::KeyPressed)
                {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) ShowMenu();
                }

            }

            break;
        }
    }
}
void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}
void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
    switch(result)
    {
        case MainMenu::Exit:
            _gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            _gameState = Game::Playing;
            break;
    }
}
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
PlayerPaddle Game::_player1;