#include <SFML/Graphics.hpp>

#define WINDOWWIDTH 500
#define WINDOWHEIGHT 500

using namespace sf;

class Ball{
public:
    Ball(sf::Vector2f &position, sf::CircleShape &sprite, sf::RenderWindow& window){
        sprite.setFillColor(Color::White);
        sprite.setPosition(position);
        sprite.setRadius(10.0f);
        sprite.setOutlineColor(Color::Black);
        sprite.setOutlineThickness(3.0f);
    }

    void Draw(sf::CircleShape &sprite, RenderWindow& window){
        window.draw(sprite);
    }

    void Update(sf::Vector2f &position, sf::Vector2f &direction, float &deltatime, sf::CircleShape& ball){
        position.x += direction.x * .1;
        position.y += direction.y * 1;

        ball.setPosition(position);
    }
};

class Player{
public:
    Player(sf::Vector2f &position, sf::RectangleShape &sprite, sf::RenderWindow& window){
        sprite.setFillColor(Color::Black);
        sprite.setPosition(position);
        sprite.setSize(sf::Vector2f(25, 80));
    }

    void Draw(sf::RectangleShape &sprite, RenderWindow& window){
        window.draw(sprite);
    }

    void Update(sf::Vector2f &position, float &deltatime, sf::RectangleShape& player){
        

        player.setPosition(position);
    }
};

int main(){

    RenderWindow window(VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "platformer!");
    Event e;

    //the ball variables here
    CircleShape mball;
    sf::Vector2f ballPosition = sf::Vector2f(WINDOWWIDTH / 2, WINDOWHEIGHT / 2);
    sf::Vector2f ballDirection = sf::Vector2f(0, 0);
    sf::FloatRect ballborder = mball.getGlobalBounds();

    Ball ball(ballPosition, mball, window);

    //the player variables here
    RectangleShape player;
    sf::Vector2f playerPosition = sf::Vector2f(15.5, WINDOWHEIGHT / 2);
    sf::FloatRect playerBorder = player.getGlobalBounds();

    Player Player(playerPosition, player, window);

    //deltatime
    sf::Clock clock;
    float dt = clock.restart().asSeconds();

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if(e.type == Event::Closed) window.close();
            
        }

        if(Keyboard::isKeyPressed(Keyboard::Space)) ballDirection.x = 1;

        switch(int(mball.getPosition().x)){
            case WINDOWWIDTH:
            ballDirection.x = -1;
            break;

            case -10:
            break;
        }

        switch(int(mball.getPosition().y)){
            
            case 0:
            ballDirection.y = 0.03;
            break;
            
            case WINDOWHEIGHT - 10:
            ballDirection.y = -0.03;
            break;
        }

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            if(player.getPosition().y > 0){
                playerPosition.y -= 0.1;
                player.setPosition(playerPosition);
            }
        }

        if(Keyboard::isKeyPressed(Keyboard::Down)){
            if(player.getPosition().y < WINDOWHEIGHT){
                playerPosition.y += 0.1;
                player.setPosition(playerPosition);
            }
        }

        if(player.getGlobalBounds().intersects(mball.getGlobalBounds())){
            ballDirection.x = 1;

            if(playerPosition.y < ballPosition.y) ballDirection.y = 0.03;
            if(playerPosition.y > ballPosition.y) ballDirection.y = -0.03;

            mball.setFillColor(Color::Blue);
        }

        ball.Update(ballPosition, ballDirection, dt, mball);

        window.clear(Color::White);

        Player.Draw(player, window);

        ball.Draw(mball, window);

        window.display();
        
    }

    return 0;
    

}