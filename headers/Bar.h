//
// Created by emiba on 4/12/2023.
//

#ifndef PONG_BAR_H
#define PONG_BAR_H
#include <SFML/Graphics.hpp>


class Bar {
private:
//Pong bar
    sf::RectangleShape pongBar;
    sf::Vector2f pongBarSize;
    sf::Vector2f pongBarPosition;
    int pongBarVelocity;


public:
    Bar(float sizeY);
    sf::Vector2f getPongBarPosition();
    void setPongBarPosition(sf::Vector2f position);
    sf::RectangleShape getPongBar();
    int getPongBarVelocity();


};


#endif //PONG_BAR_H
