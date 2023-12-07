//
// Created by emiba on 5/12/2023.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H
//define resolution
#define RESOLUTION_X 800
#define RESOLUTION_Y 600
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::CircleShape m_ball;
    int m_ballSize;
    sf::Vector2f m_ballPosition;
    sf::Vector2f m_ballSpeed;
    sf::Vector2f m_direction;



public:
    Ball();
    sf::CircleShape getBall();
    void setBallPosition(sf::Vector2f position);
    sf::Vector2f getBallPosition();
    void setBallSpeed(sf::Vector2f speed);
    sf::Vector2f getBallSpeed();
    void setBallSize(int radius);
    int getBallSize();
    void setDirection(sf::Vector2f direction);
    sf::Vector2f getDirection();
    void moveBall();
    void bounceBall(sf::Vector2f direction);
    void resetBall();



};


#endif //PONG_BALL_H
