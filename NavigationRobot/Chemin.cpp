#include "Chemin.h"

bool cheminDirectPossible(sf::Vector2f possitionUn, sf::Vector2f possitionDeux, Obstacle obstacle)
{
	
}

float* equationDeDroit(Point pointUn, Point pointDeux)
{
	int A[2][2]{
		{ pointUn.getX(), 1},
		{ pointDeux.getX(), 1}
	};
	int B[2] = { pointUn.getY(), pointDeux.getY() };
	float invA[2][2];
	float C[2];
	float detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];

	if (detA != 0)
	{
		invA[0][0] = A[1][1] * 1 / detA;
		invA[0][1] = A[1][0] * (-1) * 1 / detA;
		invA[1][0] = A[0][1] * (-1) * 1 / detA;
		invA[1][1] = A[0][0] * 1 / detA;
		C[0] = invA[0][0] * B[0] + invA[0][1] * B[1];
		C[1] = invA[1][0] * B[0] + invA[1][1] * B[1];
	}

	return C;
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
		return &possitionDeux;
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