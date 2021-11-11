#include "Point.h"

Point::Point()
{
	x_ = 0;
	y_ = 0;
}

Point::Point(float x, float y)
{
	x_ = x;
	y_ = y;
}

float Point::getX() { return x_;  }
float Point::getY() { return y_; }