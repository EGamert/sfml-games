#include <SFML/Graphics.hpp>
#include "Player.cpp"
#include "Enemy.cpp"
#include "Coin.cpp"
#include <sstream>

using namespace sf;

//MAKING A VARIABLE FOR GAMERUNNING
bool gameRunning = true;

// THE MAIN GAME STARTS HERE
int main(){

    //RENDERING A WINDOW
    RenderWindow window(VideoMode(1000, 600), "Box game!");

    //LOADING THE EVENT CLASS
    Event e;

    //LOADING THE FONT CLASS
    Font font;
    font.loadFromFile("font/Comic Sans MS.ttf");

    //ALL THE TEXT
    Text exitText;
    exitText.setFont(font);
    exitText.setFillColor(Color::Green);
    exitText.setPosition(Vector2f(0, 0));
    exitText.setString("Press ESCAPE to exit! (DONT TOUCH THE RED BOX!)");
    exitText.setScale(Vector2f(0.5f, 0.5f));

    //MAKING THE SCORE TEXT
    int score = 0;
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setFillColor(Color::Blue);
    scoreText.setPosition(sf::Vector2f(700, 0));

    //LOADING ALL THE CLASSES HERE
    Player player;
    Enemy enemy;
    Coin coin;

    //THE PLAYER POSITION INITIALLISED
    player.InitialisePosition(50, 300);
    enemy.setInitialisedPosition();
    coin.setInitialisedPosition();

    //THE MAIN GAME LOOP
    while(window.isOpen()){

        while(window.pollEvent(e)){

            //MAKING THE CLOSING SYSTEM
            if(e.type = Event::Closed){
                window.close();
            }

        }

        //making the score
        std::stringstream ss;
        ss << score;

        //CLOSING THE WINDOW BY PRESSING ESCAPE
        if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

        //HERE ARE THE COLLISION DETECTIONS

        //COLLISION OF PLAYER WITH ENEMY
        if(player.getBoundingBox().intersects(enemy.getBoundingBox())){
            gameRunning = false;   
        }

        //COLLISION OF PLAYER WITH COIN
        if(player.getBoundingBox().intersects(coin.getBoundingBox())){
            score ++;
            coin.onRight = false;
        }

        scoreText.setString(ss.str());

        //updating the player
        player.Update(.5);

        //UPDATING THE ENEMY
        enemy.Update((1 + rand()% 3), 0);

        //UPDATING THE COIN
        coin.Update((1 + rand()% 2), 0);

        //CLEARING THE WINDOW
        window.clear(Color::Black);

        if(gameRunning){
            //UPDATING THE COIN
            coin.Draw(window);

            //DRAWING THE ENEMY
            enemy.Draw(window);

            //DRAWING THE PLAYER
            player.Draw(window);

            //DRAWING THE TEXT
            window.draw(exitText);

            //DRAWING THE SCORETEXT
            window.draw(scoreText);
        }

        if(!gameRunning){

            window.clear(Color::Black);

        }

        //DISPLAYING EVERYTHING WE DREW
        window.display();

    }

    //END OF THE GAME
    return 0;
}