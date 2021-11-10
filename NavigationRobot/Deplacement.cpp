#include "Deplacement.h";

void deplacerRobot(Robot, sf::Vector2f)
{

}

sf::Vector2f calculVecteur(Point pointUn, Point pointDeux)
{
	sf::Vector2f vecteur = {
		pointUn.getX() - pointDeux.getX() ,
		pointUn.getY() - pointDeux.getY()
	};
	return vecteur;
}

void calculVitesse(sf::Vector2f, sf::Vector2f)
{

}