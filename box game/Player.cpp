#include "Player.hpp"

void Player::Draw(sf::RenderWindow& window){

    //DRAWING THE PLAYER
    playerTexture.loadFromFile("images/player.png");
    player.setTexture(playerTexture);
    window.draw(player);
}

void Player::Update(float speed){

    
    //UPDATING THE PLAYER TO MOVE UP AND DOWN

    if(player.getPosition().y < 510){
        if(Keyboard::isKeyPressed(Keyboard::Down)) position.y += 5 * speed;
    }

    if(player.getPosition().y > 0){
        if(Keyboard::isKeyPressed(Keyboard::Up)) position.y -= 5 * speed;
    }    

    player.setPosition(position);

}

void Player::InitialisePosition(int x,int y){
    
    //SETTING THE PLAYER's INITIAL POSITION
    position = sf::Vector2f(0, 300);
    player.setPosition(position);
    
}

sf::FloatRect Player::getBoundingBox(){

    //RETURNING THE PLAYER BOUNDING BOX
    boundingbox = player.getGlobalBounds();
    return boundingbox;
}

sf::Vector2f Player::getPosition(){

    //RETURNING THE PLAYER POSITION
    return position;
}