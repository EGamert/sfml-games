#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy{

private:

    //MAKING THE TEXTURE AND SPRITE FOR THE ENEMY
    sf::Sprite enemy;
    sf::Texture enemyTexture;

    //MAKING THE POSITION AND BOUNDINGBOX VARIABLES
    sf::Vector2f position;
    sf::FloatRect boundingbox;

    bool onRight;

public:

    //ALL THE ENEMY FUNCTIONS
    void Draw(sf::RenderWindow& window);
    void Update(float speed, int score);
    void setInitialisedPosition();
    
    sf::FloatRect getBoundingBox();
    sf::Vector2f getPosition();
};