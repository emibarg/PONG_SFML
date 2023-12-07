//
// Created by emiba on 5/12/2023.
//

#include <iostream>
#include "../headers/Ball.h"

Ball::Ball() {
    m_ballSize = 10;
    //spawns the ball in the middle of the screen
    m_ballPosition = sf::Vector2f(RESOLUTION_X/2, RESOLUTION_Y/2);
    m_ballSpeed =sf::Vector2f (-5,0);
    m_ball.setPosition(m_ballPosition);
    m_ball.setFillColor(sf::Color::White);
    m_ball.setRadius(m_ballSize);

}

void Ball::setBallSpeed(sf::Vector2f speed) {
    m_ballSpeed = speed;}

sf::Vector2f Ball::getBallSpeed() {return m_ballSpeed;}

void Ball::setBallPosition(sf::Vector2f position) {
    m_ballPosition = position;
    m_ball.setPosition(m_ballPosition);}

void Ball::setBallSize(int radius) {m_ballSize = radius;}

sf::CircleShape Ball::getBall() { return m_ball; }

int Ball::getBallSize() { return m_ballSize; }

void Ball::setDirection(sf::Vector2f direction) { m_direction= direction; }

sf::Vector2f Ball::getDirection() { return m_direction; }

void Ball::moveBall() {
    m_ball.move(m_ballSpeed);
    m_ballPosition = m_ball.getPosition();
}


sf::Vector2f Ball::getBallPosition() {return m_ballPosition;}
void Ball::bounceBall(sf::Vector2f direction) {
    m_direction = direction;
}

void Ball::resetBall() {
    //launches the ball from a random direction within the walls of the game screen
    m_ballPosition = sf::Vector2f(RESOLUTION_X/2 +rand()%100, RESOLUTION_Y/2 + rand()%100);
    m_ball.setPosition(m_ballPosition);
    m_ballSpeed = sf::Vector2f(rand()%10 + 1,rand()%10 + 1);
    m_ball.move(m_ballSpeed);
    m_ballPosition = m_ball.getPosition();

}
