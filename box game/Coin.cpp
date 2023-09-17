#include "Coin.hpp"

void Coin::Draw(sf::RenderWindow& window){
    coinTexture.loadFromFile("images/coin.png");
    coin.setTexture(coinTexture);

    window.draw(coin);
}

void Coin::Update(float speed, int score){
    //moving the enemy
    if(onRight){
        position.x -= 1 * speed;

        coin.setPosition(position);
    }

    //if enemy is on left

    if(position.x < -10){
        onRight = false;
    }

    if(!onRight){
        position.x = 3000;
        position.y = (1 + rand() % 500);
        coin.setPosition(position);

        onRight = true;
    }
}

void Coin::setInitialisedPosition(){
    position = sf::Vector2f(1500, 300);
    coin.setPosition(position);
    onRight = true;
}

sf::Vector2f Coin::getPosition(){
    return position;
}

sf::FloatRect Coin::getBoundingBox(){

    boundingbox = coin.getGlobalBounds();
    
    return boundingbox;
}