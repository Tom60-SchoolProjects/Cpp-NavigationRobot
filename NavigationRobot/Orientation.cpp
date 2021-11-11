#include "Orientation.h"

float calculAngle(Point pointUn, Point pointDeux)
{
	float angleCosinus;

	angleCosinus =
		(pointUn.getX() * pointDeux.getX() + pointDeux.getY() + pointDeux.getY()) /
		(sqrtf(powf(pointUn.getX(), 2) * powf(pointUn.getY(), 2)) *
			sqrtf(powf(pointDeux.getX(), 2) * powf(pointDeux.getY(), 2))
			);

	return acosf(angleCosinus);
}

void orientationRobot(Robot *robot, Point point)
{
	float angle = calculAngle(robot->getPos(), point);
	float diffAngle = angle - robot->getAngle();
	int pas = 0;

	if (angle >= 0)
		pas = 1;
	else
		pas = -1;

	for (int i = 0; i < diffAngle; i++)
		robot->setAngle(robot->getAngle() + pas);
}