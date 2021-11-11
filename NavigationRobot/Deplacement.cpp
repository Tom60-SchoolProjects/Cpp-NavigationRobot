#include "Deplacement.h";

void calculVitesse(Point pointDepart, Point pointArriver, Point pointActuel, int* vitesse)
{
	int distTotal = abs(pointDepart.getX() - pointArriver.getX()) + abs(pointDepart.getY() - pointArriver.getY());
	int distRestante = abs(pointDepart.getX() - pointArriver.getX()) + abs(pointActuel.getY() - pointActuel.getY());
	int distVitesseCroisière = 10;

	if (distRestante > distTotal - distVitesseCroisière) // Dans la zone d'accélération
		vitesse += 1; // Augmente la vitesse
	else if (distRestante < distVitesseCroisière) // Dans la zonde de décélération
		vitesse -= 1; // Diminue la vitesse
}

sf::Vector2f calculVecteur(Point pointUn, Point pointDeux)
{
	sf::Vector2f vecteur = {
		pointUn.getX() - pointDeux.getX() ,
		pointUn.getY() - pointDeux.getY()
	};
	return vecteur;
}

// https://www.mathworks.com/matlabcentral/answers/390111-how-can-i-draw-a-particular-line-pixel-by-pixel
void deplacerRobot(Robot *robot, Point pointArriver, Scene* window)
{
	Point pointDepart = robot->getPos();
	int vitesse = 0;

	std::cout << "Deplacement du robot vers la position ";
	robot->getPos().print();
	std::cout << std::endl;

	calculVitesse(pointDepart, pointArriver, robot->getPos(), &vitesse);

	sf::Vector2f vecteur = calculVecteur(pointArriver, pointDepart);
	float m = vecteur.y / vecteur.x;
	float b = pointDepart.getY() - (m * pointDepart.getX());
	float invm = 1 / m;
	float invmb = b * invm;
	float x = 0;
	float y = 0;

	if (m <= 1)
		for (y = pointDepart.getY(); y > pointArriver.getY(); y++)
		{
			x = invm * x - invmb;
			float xp = floor(0.5 + x);
			robot->setPosition(xp, y);
			window->Update();
		}
	else
		for (x = pointDepart.getX(); x > pointArriver.getX(); x++)
		{
			y = (m * x) + b;
			float yp = floor(0.5 + y);
			robot->setPosition(x, yp);
			window->Update();
		}
}