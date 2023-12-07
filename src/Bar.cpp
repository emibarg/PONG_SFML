//
// Created by emiba on 4/12/2023.
//

#include "../headers/Bar.h"

Bar::Bar(float sizeY) {
    pongBarSize = sf::Vector2f(25, sizeY);
    pongBarPosition = sf::Vector2f(40, 25);
    pongBarVelocity = 10;
    pongBar.setSize(pongBarSize);
    pongBar.setPosition(pongBarPosition);
    pongBar.setFillColor(sf::Color::White);
}

sf::RectangleShape Bar::getPongBar() {
    return pongBar;
}

sf::Vector2f Bar::getPongBarPosition() {
    return pongBarPosition;
}

void Bar::setPongBarPosition(sf::Vector2f position) {
    pongBarPosition = position;
    pongBar.setPosition(pongBarPosition);
}
int Bar::getPongBarVelocity() {
    return pongBarVelocity;
}
