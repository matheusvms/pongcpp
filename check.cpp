#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    window.setFramerateLimit(240);
    //sf::CircleShape shape(400.f);
    //shape.setFillColor(sf::Color::Green);

    Texture texture;
    texture.loadFromFile("spiral.png");

    Sprite sprite(texture);
    sprite.scale(sf::Vector2f(0.2f, 0.2f));
    sprite.setPosition(150.f, 150.f);
    sprite.setOrigin(600.f, 600.f);
    double rot_count = 0;
    bool rot_a = 1;
    int frame_rate = 60;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    if (rot_a == 1){
                        rot_a = 0;
                    } else {
                        rot_a = 1;
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    if (frame_rate <= 960){
                        frame_rate += 60;
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    if (frame_rate >= 120){
                        frame_rate -= 60;
                    }
                }


            }
        }
        window.clear(sf::Color::White);
        if (rot_count == 360){
            rot_count = 0;
        }
        if (rot_a == 1) {
            sprite.setRotation(rot_count++);
        }
        window.setFramerateLimit(frame_rate);
        window.draw(sprite);
        window.display();
    }
    return 0;
}
