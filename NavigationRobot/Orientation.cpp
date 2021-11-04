#include "Orientation.h"

void orientationRobot(Robot robot, sf::Vector2f point)
{

}

void calculAngle(sf::Vector2f vecteurUn, sf::Vector2f vecteurDeux)
{
	float angleCosinus;

	angleCosinus =
		(vecteurUn.x * vecteurDeux.x + vecteurDeux.y + vecteurDeux.y) /
		(sqrtf(powf(vecteurUn.x, 2) * powf(vecteurUn.y, 2)) *
		sqrtf(powf(vecteurDeux.x, 2) * powf(vecteurDeux.y, 2))
	);
}