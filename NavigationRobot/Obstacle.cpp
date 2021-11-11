#include "Obstacle.h"

Obstacle::Obstacle()
{
	lines[0].color = sf::Color::Black;
	lines[1].color = sf::Color::Black;
}

Obstacle::Obstacle(sf::Vector2f vecteurUn, sf::Vector2f vecteurDeux)
{
	lines[0].position = vecteurUn;
	lines[0].color = sf::Color::Black;
	lines[1].position = vecteurDeux;
	lines[1].color = sf::Color::Black;
}

void Obstacle::setPosition(sf::Vector2f vecteurUn, sf::Vector2f vecteurDeux)
{
	lines[0].position.x = vecteurUn.x * 10;
	lines[0].position.y = vecteurUn.y * 10;
	lines[1].position.x = vecteurDeux.x * 10;
	lines[1].position.y = vecteurDeux.y * 10;
}

sf::Vector2f Obstacle::getPointOne()
{
	return lines[0].position;
}

sf::Vector2f Obstacle::getPointTwo()
{
	return lines[1].position;
}

sf::Vertex* Obstacle::getShape()
{
	return lines;
}
