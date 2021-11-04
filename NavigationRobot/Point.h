#pragma once

class Point
{
public:
	Point(int, int);

	int getPosX();
	int getPosY();
private:
	int posX, posY;
};