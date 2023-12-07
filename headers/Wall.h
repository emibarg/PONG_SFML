//
// Created by emiba on 5/12/2023.
//

#ifndef PONG_WALL_H
#define PONG_WALL_H
#include <SFML/Graphics.hpp>

class Wall {
private:
    sf::RectangleShape m_wall;
    sf::Vector2f m_wallSize;
    sf::Vector2f m_wallPosition;
public:
    Wall(sf::Vector2f size, sf::Vector2f position);
    sf::RectangleShape getWall();
    sf::Vector2f getWallSize();
    sf::Vector2f getWallPosition();
    void setWallPosition(sf::Vector2f position);



};


#endif //PONG_WALL_H
