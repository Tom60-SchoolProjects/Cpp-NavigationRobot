#include "Robot.h"

Robot::Robot()
{
	sf::Vector2f size(larg, haut);
	robot.setSize(size);
	robot.setFillColor(sf::Color::Cyan);
}

Robot::Robot(int x, int y)
{
	sf::Vector2f size(larg, haut);
	robot.setSize(size);
	robot.setFillColor(sf::Color::Cyan);
	setPosition(x, y);
}

int Robot::getPosX()
{
	return posX;
}

int Robot::getPosY()
{
	return posY;
}

sf::RectangleShape Robot::getShape()
{
	return robot;
}

void Robot::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	robot.setPosition(posX, posY);
}