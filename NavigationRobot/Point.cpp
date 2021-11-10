#include "Point.h"

Point::Point(int x, int y)
{
	x_ = x;
	y_ = y;
}

int Point::getX() { return x_;  }
int Point::getY() { return y_; }