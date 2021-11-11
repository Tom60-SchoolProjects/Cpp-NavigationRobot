#include "Robot.h"

Robot::Robot()
{
	sf::Vector2f size(larg, haut);
	robot.setSize(size);
	robot.setFillColor(sf::Color::Color(155, 175, 181));
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

Point Robot::getPos()
{
	Point point { posX, posY };
	return point;
}

float Robot::getAngle()
{
	return angle;
}

sf::RectangleShape Robot::getShape()
{
	return robot;
}

void Robot::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	robot.setPosition(
		(x * 10) - larg / 2,
		(y * 10) - haut / 2
	);
}

void Robot::setAngle(float angle)
{
	Robot::angle = angle;
	robot.setRotation(angle);
}