#include <iostream>
#include "Scene.h"
#include "Robot.h"
#include "Obstacle.h"
#include "Chemin.h"
#include "Orientation.h"
#include "Deplacement.h"

Scene screen;

void navigationRobot()
{
	std::vector<Point> chemins;

	chemins = calculCheminOptimal(screen.robotD.getPos(), screen.robotA.getPos(), screen.obstacle);

	for (Point chemin : chemins) //(int i = 0; i > sizeof(chemins) / sizeof(Point); i++)
	{
		//Point chemin = chemins[i];

		orientationRobot(&screen.robotD, chemin, &screen);
		deplacerRobot(&screen.robotD, chemin, &screen);
		std::cout << "Fin du chemin";
	}

	screen.robotD.setAngle(screen.robotA.getAngle());
	screen.Update();
}

/*void update()
{
	/*window.draw(robotD.getShape());
	window.draw(robotA.getShape());
	window.draw(obstacle.getShape(), 2, sf::Lines);*//*
}*/

int main()
{
	sf::Vector2f obstPoint1;
	sf::Vector2f obstPoint2;
	sf::Clock clock;
	int x , y;

	screen.window.setVisible(false);

	std::cout << "Entrer la position de depart du robot" << std::endl;
	std::cout << "X: "; std::cin >> x;
	std::cout << "Y: "; std::cin >> y;
	screen.robotD.setPosition(x, y);

	std::cout << "Entrer la position d'arrivee du robot" << std::endl;
	std::cout << "X: "; std::cin >> x;
	std::cout << "Y: "; std::cin >> y;
	screen.robotA.setPosition(x, y);

	std::cout << "Entrer la position de l'obstacle du robot" << std::endl;
	std::cout << "X1: "; std::cin >> x;
	std::cout << "Y1: "; std::cin >> y;
	obstPoint1 = sf::Vector2f(x, y);
	std::cout << "X2: "; std::cin >> x;
	std::cout << "Y2: "; std::cin >> y;
	obstPoint2 = sf::Vector2f(x, y);
	screen.obstacle.setPosition(obstPoint1, obstPoint2);

	std::cout << "Demarage de la visualisation..." << std::endl;

	screen.window.setVisible(true);
	// Init draw
	screen.Update();

	navigationRobot();

	while (screen.window.isOpen())
	{
		sf::Event event;
		while (screen.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				screen.window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					return 0;
			}
		}

		if (clock.getElapsedTime().asMilliseconds() > 10)
		{
			//update();
			clock.restart();
		}
	}
	screen.window.close();
}