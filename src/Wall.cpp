//
// Created by emiba on 5/12/2023.
//

#include "../headers/Wall.h"

Wall::Wall(sf::Vector2f size, sf::Vector2f position) {
    m_wallSize = size;
    m_wallPosition = position;
    m_wall.setSize(m_wallSize);
    m_wall.setPosition(m_wallPosition);
    m_wall.setFillColor(sf::Color::White);
}

sf::RectangleShape Wall::getWall() { return m_wall; }

void Wall::setWallPosition(sf::Vector2f position) {
    m_wallPosition = position;
    m_wall.setPosition(m_wallPosition);}


sf::Vector2f Wall::getWallPosition() { return m_wallPosition; }

