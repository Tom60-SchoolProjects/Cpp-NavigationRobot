#pragma once

#include <iostream>

class Point
{
	float x_;
	float y_;

public:
	Point();
	Point(float, float);

	void print();

	float getX();
	float getY();
};