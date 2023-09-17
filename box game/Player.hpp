#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Player{

private:

    // MAKING THE SPRITE AND THE PLAYER
    sf::Sprite player;
    sf::Texture playerTexture;

    //MAKING THE POSITION AND BOUNDING BOX VARIABLE
    sf::Vector2f position;
    sf::FloatRect boundingbox;

public:
    
    //ALL THE FUNCTIONS OF THE PLAYER
    void Draw(sf::RenderWindow &window);
    void Update(float speed);
    void InitialisePosition(int x, int y);

    sf::FloatRect getBoundingBox();
    sf::Vector2f getPosition();
};
