//
// Created by emiba on 4/12/2023.
//

#include <iostream>
#include "../headers/Engine.h"


const sf::Time timePerFrame = sf::seconds(1.f/60.f);

Engine::Engine():resolution {sf::Vector2f(800, 600)},playerBar(100), enemyBar(100),topWall(sf::Vector2f(resolution.x, 10),sf::Vector2f(0, 0)), bottomWall(sf::Vector2f(resolution.x, 10),sf::Vector2f(0, resolution.y - 10) ),leftWall( sf::Vector2f(10, resolution.y),sf::Vector2f(0, 0)),rightWall( sf::Vector2f(10, resolution.y),sf::Vector2f(resolution.x - 10, 0)), ball(){
//Window
    const unsigned int FPS = 60;
    window.create(sf::VideoMode(resolution.x, resolution.y), "Pong", sf::Style::None);
    window.setFramerateLimit(FPS);
    currentGameState = GameState::PLAYING;
    currentFrameNumber = 0;
    enemyBar.setPongBarPosition(sf::Vector2f(resolution.x - enemyBar.getPongBar().getGlobalBounds().width - 40, 25));
    timesCollided = 0;
    if (!shader.loadFromFile("../../assets/shaders/glow.frag", sf::Shader::Fragment)) {
        // handle error
        std::cout<< "error loading shader" << std::endl;
    }
    shader.setUniform("glowColor", sf::Glsl::Vec4(1.0, 1.0, 1.0, 1.0)); // white glow
    shader.setUniform("glowSize", 0.4f);

    //score
    playerScore = 0;
    enemyScoreInt = 0;
    if (!font.loadFromFile("../../assets/fonts/RetroGaming.ttf")) {
        // handle error
        std::cout<< "error loading font" << std::endl;
    }
    score.setFont(font);
    score.setCharacterSize(24);
    score.setString(std::to_string(playerScore));
    score.setPosition(sf::Vector2f(resolution.x/2 - score.getGlobalBounds().width - 10, 10));
    score.setFillColor(sf::Color::White);
    enemyScore.setFont(font);
    enemyScore.setCharacterSize(24);
    enemyScore.setString(std::to_string(enemyScoreInt));
    enemyScore.setPosition(sf::Vector2f(resolution.x/2 + 10, 10));
    enemyScore.setFillColor(sf::Color::White);

    //pause text
    pauseText.setFont(font);
    pauseText.setCharacterSize(60);
    pauseText.setString("PAUSED");
    pauseText.setPosition(sf::Vector2f(resolution.x/2 - pauseText.getGlobalBounds().width/2, resolution.y/2 - pauseText.getGlobalBounds().height/2));
    pauseText.setFillColor(sf::Color::White);
    //game over text
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setString("GAME OVER");
    gameOverText.setPosition(sf::Vector2f(resolution.x/2 - gameOverText.getGlobalBounds().width/2, resolution.y/2 - gameOverText.getGlobalBounds().height/2));
    gameOverText.setFillColor(sf::Color::White);
    gameOverText2.setFont(font);
    gameOverText2.setCharacterSize(40);
    gameOverText2.setString("Press R to restart");
    gameOverText2.setPosition(sf::Vector2f(resolution.x/2 - gameOverText2.getGlobalBounds().width/2, resolution.y/2 - gameOverText2.getGlobalBounds().height/2 + 60));
    gameOverText2.setFillColor(sf::Color::White);



}


void Engine::run(){
    sf::Clock clock;

    while (window.isOpen()){
        sf::Time deltaTime = clock.restart();

        if (currentGameState == GameState::PAUSED || currentGameState == GameState::GAMEOVER) {
            //If paused check for input to unpause
            input();
            render();

            if (currentGameState == GameState::GAMEOVER) {
                render();
            }
            sleep(sf::milliseconds(2));
            continue;
        }

        timeSinceLastMove += deltaTime;   //adds delta time to time since last move
        currentFrameNumber++;
        input();
        update();
        render();

    }
}