//
// Created by sofia on 06/12/2020.
//

#ifndef PONGCPP_VISIBLEGAMEOBJECT_H
#define PONGCPP_VISIBLEGAMEOBJECT_H

#endif //PONGCPP_VISIBLEGAMEOBJECT_H
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#pragma once
class VisibleGameObject
{
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow & window);

    virtual void SetPosition(float x, float y);

private:
    sf::Sprite  _sprite;
    sf::Texture _image;
    std::string _filename;
    bool _isLoaded;

};