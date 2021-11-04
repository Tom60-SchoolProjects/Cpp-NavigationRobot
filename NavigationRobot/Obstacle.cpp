#include "Obstacle.h"

Obstacle::Obstacle(sf::Vector2f vecteurUn, sf::Vector2f vecteurDeux)
{
	line[0].position = vecteurUn;
	line[0].color = sf::Color::Black;
	line[1].position = vecteurDeux;
	line[1].color = sf::Color::Black;
}

sf::Vector2f Obstacle::getPointOne()
{
	return line[0].position;
}

sf::Vector2f Obstacle::getPointTwo()
{
	return line[1].position;
}
