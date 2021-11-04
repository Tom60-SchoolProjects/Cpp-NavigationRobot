#pragma once

#include <SFML/Graphics.hpp>

class Obstacle
{
public:
	Obstacle(sf::Vector2f, sf::Vector2f);

	sf::Vector2f getPointOne();
	sf::Vector2f getPointTwo();
private:
	sf::Vertex line[2];
};