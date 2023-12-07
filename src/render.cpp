//
// Created by emiba on 4/12/2023.
//
#include "../headers/Engine.h"
#include <iostream>

void Engine::render() {

    if (currentGameState == GameState::PLAYING) {
        window.clear();
        window.draw(playerBar.getPongBar());
        window.draw(enemyBar.getPongBar());
        window.draw(topWall.getWall());
        window.draw(bottomWall.getWall());
        window.draw(leftWall.getWall());
        window.draw(rightWall.getWall());
        window.draw(ball.getBall(), &shader);
        window.draw(score);
        window.draw(enemyScore);
        window.display();
    }

    if (currentGameState == GameState::PAUSED) {
        window.clear();
        window.draw(pauseText);
        window.display();
    }
    if (currentGameState == GameState::GAMEOVER) {
        window.clear();
        window.draw(gameOverText);
        window.draw(gameOverText2);
        window.display();
    }
}