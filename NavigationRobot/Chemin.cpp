#include <math.h>
#include "Chemin.h"
#include "Obstacle.h"

bool cheminDirectPossible(sf::Vector2f possitionUn, sf::Vector2f possitionDeux, Obstacle obstacle)
{
	
}

int calculDistance(sf::Vector2f possitionUn, sf::Vector2f possitionDeux)
{
	return sqrtf(
		powf((possitionDeux.y - possitionUn.x), 2) +
		powf((possitionDeux.y - possitionUn.y), 2)
	);
}

sf::Vector2f* calculCheminOptimal(sf::Vector2f possitionUn, sf::Vector2f possitionDeux, Obstacle obstacle)
{
	int distanceUn, distanceDeux;

	if (cheminDirectPossible(possitionUn, possitionDeux, obstacle))
	{
		sf::Vector2f retour[1] = { possitionDeux };
		return retour;
	}
	else
	{
		distanceUn = calculDistance(possitionUn, obstacle.getPointOne()) +
			calculDistance(obstacle.getPointTwo(), possitionDeux);
		distanceDeux = calculDistance(possitionUn, obstacle.getPointTwo()) +
			calculDistance(obstacle.getPointTwo(), possitionDeux);

		sf::Vector2f retour[2] = {
			possitionDeux,
			(distanceUn < distanceDeux ? obstacle.getPointOne() : obstacle.getPointTwo())
		};
		
		return retour;
	}

	return 0;
}