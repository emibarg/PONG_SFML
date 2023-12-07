//
// Created by emiba on 4/12/2023.
//
#include "../headers/Engine.h"
#include <iostream>
#include <cmath>

void Engine::update() {
//Update player bar
    if (!directionQueue.empty()) {
        int direction = directionQueue.front();
        directionQueue.pop();
        if (direction == UP) {
            playerBar.setPongBarPosition(sf::Vector2f(playerBar.getPongBarPosition().x,
                                                      playerBar.getPongBarPosition().y - playerBar.getPongBarVelocity()));
        checkCollisionsBarWall();
        }
        if (direction == DOWN) {
            playerBar.setPongBarPosition(sf::Vector2f(playerBar.getPongBarPosition().x,
                                                      playerBar.getPongBarPosition().y + playerBar.getPongBarVelocity()));
        checkCollisionsBarWall();
        }
    }
checkCollisionsBallWall();
checkCollisionsBallBar();
ball.moveBall();
enemyAI();
    if (playerScore == 5 || enemyScoreInt == 5){
        currentGameState = GAMEOVER;
    }

}

void Engine::checkCollisionsBarWall() {
    //check bar colission with walls
    if (playerBar.getPongBar().getGlobalBounds().intersects(topWall.getWall().getGlobalBounds())) {
        playerBar.setPongBarPosition(sf::Vector2f(playerBar.getPongBarPosition().x, topWall.getWall().getGlobalBounds().height));
    }
    if (playerBar.getPongBar().getGlobalBounds().intersects(bottomWall.getWall().getGlobalBounds())) {
        playerBar.setPongBarPosition(sf::Vector2f(playerBar.getPongBarPosition().x, bottomWall.getWall().getGlobalBounds().top - playerBar.getPongBar().getGlobalBounds().height));
    }
    //enemy bar
    if (enemyBar.getPongBar().getGlobalBounds().intersects(topWall.getWall().getGlobalBounds())) {
        enemyBar.setPongBarPosition(sf::Vector2f(enemyBar.getPongBarPosition().x, topWall.getWall().getGlobalBounds().height));
    }
    if (enemyBar.getPongBar().getGlobalBounds().intersects(bottomWall.getWall().getGlobalBounds())) {
        enemyBar.setPongBarPosition(sf::Vector2f(enemyBar.getPongBarPosition().x, bottomWall.getWall().getGlobalBounds().top - enemyBar.getPongBar().getGlobalBounds().height));
    }
}

void Engine::checkCollisionsBallWall() {
    //check ball colission with walls

    if (ball.getBall().getGlobalBounds().intersects(topWall.getWall().getGlobalBounds())) {
        ball.setBallPosition(sf::Vector2f(ball.getBallPosition().x, topWall.getWall().getGlobalBounds().height));
        ball.setBallSpeed(sf::Vector2f(ball.getBallSpeed().x, -ball.getBallSpeed().y));
    }
    if (ball.getBall().getGlobalBounds().intersects(bottomWall.getWall().getGlobalBounds())) {
        ball.setBallPosition(sf::Vector2f(ball.getBallPosition().x, bottomWall.getWall().getGlobalBounds().top - ball.getBall().getGlobalBounds().height));
        ball.setBallSpeed(sf::Vector2f(ball.getBallSpeed().x, -ball.getBallSpeed().y));
    }
    if (ball.getBall().getGlobalBounds().intersects(leftWall.getWall().getGlobalBounds())) {

        enemyScoreInt++;
        enemyScore.setString(std::to_string(enemyScoreInt));
        ball.resetBall();

    }
    if (ball.getBall().getGlobalBounds().intersects(rightWall.getWall().getGlobalBounds())) {

        ball.resetBall();
        playerScore++;
        score.setString(std::to_string(playerScore));

    }

}

void Engine::checkCollisionsBallBar() {
    // Check ball collision with player's bar
    if (ball.getBall().getGlobalBounds().intersects(playerBar.getPongBar().getGlobalBounds())) {
        float relativePos = ((playerBar.getPongBar().getGlobalBounds().top + playerBar.getPongBar().getGlobalBounds().height - ball.getBallPosition().y) / playerBar.getPongBar().getGlobalBounds().height) * 2 - 1;
        float bounceAngle = relativePos * (3.14159f / 3.f); // Bounce angle varies from -60 to 60 degrees

        sf::Vector2f newSpeed((-ball.getBallSpeed().x) + 0.001*timesCollided++ , -std::sin(bounceAngle) *5+0.001*timesCollided++ );
        ball.setBallSpeed(newSpeed);


    }
    if (ball.getBall().getGlobalBounds().intersects(enemyBar.getPongBar().getGlobalBounds())) {
        float relativePos = ((enemyBar.getPongBar().getGlobalBounds().top + enemyBar.getPongBar().getGlobalBounds().height - ball.getBallPosition().y) / enemyBar.getPongBar().getGlobalBounds().height) * 2 - 1;
        float bounceAngle = relativePos * (3.14159f / 3.f); // Bounce angle varies from -60 to 60 degrees

        sf::Vector2f newSpeed(- ball.getBallSpeed().x - 0.001*timesCollided++, -std::sin(bounceAngle) *5+0.001*timesCollided++ );
        ball.setBallSpeed(newSpeed);

    }

}


void Engine::enemyAI() {
   //its good but not that good has a max speed
   int maxSpeed =3 ;
    if (ball.getBallPosition().y < enemyBar.getPongBarPosition().y + enemyBar.getPongBar().getGlobalBounds().height/2) {
        enemyBar.setPongBarPosition(sf::Vector2f(enemyBar.getPongBarPosition().x,
                                                 enemyBar.getPongBarPosition().y - maxSpeed));
        checkCollisionsBarWall();
    }
    if (ball.getBallPosition().y > enemyBar.getPongBarPosition().y + enemyBar.getPongBar().getGlobalBounds().height/2) {
        enemyBar.setPongBarPosition(sf::Vector2f(enemyBar.getPongBarPosition().x,
                                                 enemyBar.getPongBarPosition().y + maxSpeed));
        checkCollisionsBarWall();
    }


}