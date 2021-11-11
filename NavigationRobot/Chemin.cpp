#include "Chemin.h"

Droite equationDeDroit(Point pointUn, Point pointDeux)
{
	Droite droite;

	if (pointDeux.getX() == pointUn.getX() && pointDeux.getX() != pointUn.getX())
	{
		droite.vertical = true;
		droite.b = pointUn.getX();
	}
	else
	{
		droite.vertical = false;
		droite.a = (pointDeux.getY() - pointUn.getY()) / (pointDeux.getX() - pointUn.getX());
		droite.b = pointUn.getY() - droite.a * pointUn.getX();
	}

	return droite;
}

bool cheminDirectPossible(Droite droiteUn, Droite droiteDeux, Obstacle obstacle)
{
	sf::Vector2f vecObsUn = obstacle.getPointOne();
	sf::Vector2f vecObsDeux = obstacle.getPointTwo();

	if(droiteUn.vertical && droiteDeux.vertical || droiteUn.a == 0 && droiteDeux.a == 0 || droiteUn.a == droiteDeux.a)
		return true;
	if (droiteUn.a == 0 && droiteDeux.vertical)
		return !(droiteDeux.b >= fmin(vecObsUn.x, vecObsDeux.x) && droiteDeux.b <= fmax(vecObsUn.x, vecObsDeux.x) && droiteUn.b >= fmin(vecObsUn.y, vecObsDeux.y) && droiteUn.b <= fmax(vecObsUn.y, vecObsDeux.y));
	if (droiteDeux.a == 0 && droiteUn.vertical)
		return !(droiteUn.b >= fmin(vecObsUn.x, vecObsDeux.x) && droiteUn.b <= fmax(vecObsUn.x, vecObsDeux.x) && droiteDeux.b >= fmin(vecObsUn.y, vecObsDeux.y) && droiteDeux.b <= fmax(vecObsUn.y, vecObsDeux.y));
	if (droiteUn.vertical)
		return !(droiteUn.b >= fmin(vecObsUn.x, vecObsDeux.x) && droiteUn.b <= fmax(vecObsUn.x, vecObsDeux.x) && droiteDeux.a * droiteUn.b + droiteDeux.b >= fmin(vecObsUn.y, vecObsDeux.y) && droiteDeux.a * droiteUn.b + droiteDeux.b <= fmax(vecObsUn.y, vecObsDeux.y));
	if (droiteDeux.vertical)
		return !(droiteDeux.b >= fmin(vecObsUn.x, vecObsDeux.x) && droiteDeux.b <= fmax(vecObsUn.x, vecObsDeux.x) && droiteUn.a * droiteDeux.b + droiteUn.b >= fmin(vecObsUn.y, vecObsDeux.y) && droiteUn.a * droiteDeux.b + droiteUn.b <= fmax(vecObsUn.y, vecObsDeux.y));
	if (droiteUn.a == 0)
		return !((droiteUn.b - droiteDeux.b) / droiteDeux.a >= fmin(vecObsUn.x, vecObsDeux.x) && (droiteUn.b - droiteDeux.b) / droiteDeux.a <= fmax(vecObsUn.x, vecObsDeux.x) && droiteUn.b >= fmin(vecObsUn.y, vecObsDeux.y) && droiteUn.b <= fmax(vecObsUn.y, vecObsDeux.y));
	if (droiteDeux.a == 0)
		return !((droiteDeux.b - droiteUn.b) / droiteUn.a >= fmin(vecObsUn.x, vecObsDeux.x) && (droiteDeux.b - droiteUn.b) / droiteUn.a <= fmax(vecObsUn.x, vecObsDeux.x) && droiteDeux.b >= fmin(vecObsUn.y, vecObsDeux.y) && droiteDeux.b <= fmax(vecObsUn.y, vecObsDeux.y));

	int A[2][2], B[2], invA[2][2];
	float C[2];
	float detA;

	A[0][0] = droiteUn.a;
	A[0][1] = 1;
	A[1][0] = droiteDeux.a;
	A[1][1] = 1;
	B[0] = droiteUn.b;
	B[1] = droiteDeux.b;
	detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	invA[0][0] = (float)A[1][1] / (float)detA;
	invA[0][1] = (float)A[1][0] * (-1) / (float)detA;
	invA[1][0] = (float)A[0][1] * (-1) / (float)detA;
	invA[1][1] = (float)A[0][0] / (float)detA;
	C[0] < -invA[0][0] * (float)B[0] + invA[0][1] * (float)B[1];
	C[1] < -invA[1][0] * (float)B[0] + invA[1][1] * (float)B[1];
	return !(C[0] >= fmin(vecObsUn.x, vecObsDeux.x) && C[0] <= fmax(vecObsUn.x, vecObsDeux.x) && C[1] >= fmin(vecObsUn.y, vecObsDeux.y) && C[1] <= fmax(vecObsUn.y, vecObsDeux.y));
}

int calculDistance(Point possitionUn, Point possitionDeux)
{
	return sqrtf(
		powf((possitionDeux.getX() - possitionUn.getX()), 2) +
		powf((possitionDeux.getY() - possitionUn.getY()), 2)
	);
}

std::vector<Point> calculCheminOptimal(Point possitionUn, Point possitionDeux, Obstacle obstacle)
{
	int distanceUn, distanceDeux;
	sf::Vector2f vecUn = obstacle.getPointOne();
	Point pointObstacleUn = { vecUn.x, vecUn.y };

	sf::Vector2f vecDeux = obstacle.getPointOne();
	Point pointObstacleDeux = { vecDeux.x, vecDeux.y };

	// Droites
	Droite droiteRobots = equationDeDroit(possitionUn, possitionDeux);
	Droite droiteObstacle = equationDeDroit(pointObstacleUn, pointObstacleDeux);

	// Verif
	if (cheminDirectPossible(droiteRobots, droiteObstacle, obstacle))
	{
		std::cout << "Le robot peut aller directement a l'arrivee sans rencontres d'obstacle." << std::endl;
		std::vector<Point> vecUn = { possitionDeux };
		return vecUn;
	}
	else
	{
		distanceUn = calculDistance(possitionUn, pointObstacleUn) +
			calculDistance(pointObstacleDeux, possitionDeux);
		distanceDeux = calculDistance(possitionUn, pointObstacleDeux) +
			calculDistance(pointObstacleDeux, possitionDeux);

		std::vector<Point> vecDeux = {
			possitionDeux,
			(distanceUn < distanceDeux ? pointObstacleUn : pointObstacleDeux)
		};
		
		return vecDeux;
	}

	std::vector<Point> vecZero;
	return vecZero;
}
