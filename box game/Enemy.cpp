#include "Enemy.hpp"

void Enemy::Draw(sf::RenderWindow& window){
    //THE SPRITE AND TEXTURE LOADING
    enemyTexture.loadFromFile("images/enemy.png");
    enemy.setTexture(enemyTexture);
    window.draw(enemy);
}

void Enemy::Update(float speed, int score){
    //moving the enemy
    if(onRight){
        position.x -= 1 * speed;

        enemy.setPosition(position);
    }

    //if enemy is on left

    if(position.x < -10){
        onRight = false;
    }

    if(!onRight){
        position.x = 2000;
        position.y = (1 + rand() % 500);
        enemy.setPosition(position);
        score ++;

        onRight = true;
    }
}

void Enemy::setInitialisedPosition(){
    position = sf::Vector2f(500, 300);
    enemy.setPosition(position);
    onRight = true;
}

sf::Vector2f Enemy::getPosition(){

    //GETTING THE POSITION
    return position;
}

sf::FloatRect Enemy::getBoundingBox(){

    //GETTING THE BOUNDINGBOX VARIABLE
    boundingbox = enemy.getGlobalBounds();
    return boundingbox;
}