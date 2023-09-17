#pragma once
#include <SFML/Graphics.hpp>

class Coin{
private:

    //MAKING THE TEXTURE AND SPRITE FOR THE ENEMY
    sf::Sprite coin;
    sf::Texture coinTexture;

    //MAKING THE POSITION AND BOUNDINGBOX VARIABLES
    sf::Vector2f position;
    sf::FloatRect boundingbox;

public:

    bool onRight;

    //ALL THE ENEMY FUNCTIONS
    void Draw(sf::RenderWindow& window);
    void Update(float speed, int score);
    void setInitialisedPosition();
    
    sf::FloatRect getBoundingBox();
    sf::Vector2f getPosition();

};