//
// Created by emiba on 4/12/2023.
//

#ifndef PONG_ENGINE_H
#define PONG_ENGINE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <queue>
#include "../headers/Bar.h"
#include "../headers/Wall.h"
#include "../headers/Ball.h"



class Engine {
private:
    //Window
    sf::RenderWindow window;
    sf::Vector2f resolution;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    static const sf::Time timePerFrame;
    int currentFrameNumber;
    sf::Time timeSinceLastMove;
    sf::Shader shader;

    //Player bar
    Bar playerBar;
    std::queue<int> directionQueue;



    //Pong ball
    Ball ball;
    //Enemy bar
    Bar enemyBar;

    //Walls
    Wall topWall;
    Wall bottomWall;
    Wall leftWall;
    Wall rightWall;


    //font
    sf::Font font;
    sf::Text text;
    sf::Text score;
    sf::Text enemyScore;
    int playerScore;
    int enemyScoreInt;
    sf::Text pauseText;
    sf::Text gameOverText;
    sf::Text gameOverText2;
    //state
    int currentGameState;

public:
    Engine();
    enum GameState{PAUSED, PLAYING, GAMEOVER};
    enum Direction{UP, DOWN, LEFT, RIGHT};
    void run();
    void update();
    void render();
    void input();
    void addDirectionToQueue(int direction);
    void checkCollisionsBarWall();
    void checkCollisionsBallWall();
    void checkCollisionsBallBar();
    int timesCollided;

    //enemy AI
    void enemyAI();

};


#endif //PONG_ENGINE_H
