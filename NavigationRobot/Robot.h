#pragma once

#include <SFML/Graphics.hpp>
//#include "Scene.h"
#include "Point.h"

class Robot
{
public:
	const int larg = 40, haut = 24;

	Robot();
	Robot(int, int);

	int getPosX();
	int getPosY();
	Point getPos();
	float getAngle();
	sf::RectangleShape getShape();
	void setPosition(int, int);
	void setAngle(float);

private:
	float posX, posY;
	float angle;
	sf::RectangleShape robot;
};