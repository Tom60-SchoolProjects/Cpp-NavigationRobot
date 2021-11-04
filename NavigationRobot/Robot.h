#pragma once

#include <SFML/Graphics.hpp>

class Robot
{
public:
	const int larg = 100, haut = 10, vitesse = 2;

	Robot();
	Robot(int, int);

	int getPosX();
	int getPosY();
	sf::RectangleShape getShape();
	void setPosition(int, int);
	void setAngle(int);

private:
	int posX, posY;
	sf::RectangleShape robot;
};