//
// Created by emiba on 4/12/2023.
//
#include <iostream>
#include "../headers/Engine.h"

void Engine::input() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            break;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
                break;
            }
            if (event.key.code == sf::Keyboard::Up) {
                addDirectionToQueue(UP);
            }
            if (event.key.code == sf::Keyboard::Down) {
                addDirectionToQueue(DOWN);
            }
            if (event.key.code == sf::Keyboard::P){
                if (currentGameState == PAUSED){
                    currentGameState = PLAYING;
                } else if (currentGameState == PLAYING){
                    currentGameState = PAUSED;
                }

            }
            if (event.key.code == sf::Keyboard::R){
                if (currentGameState == GAMEOVER) {
                    playerScore = 0;
                    enemyScoreInt = 0;
                    score.setString(std::to_string(playerScore));
                    enemyScore.setString(std::to_string(enemyScoreInt));
                    currentGameState = PLAYING;
                    ball.resetBall();
                }}


        }
    }
}

void Engine::addDirectionToQueue(int direction) {
    directionQueue.push(direction);
}