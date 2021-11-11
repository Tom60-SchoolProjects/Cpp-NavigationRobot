#pragma once

#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Robot.h"
#include "Obstacle.h"

struct Scene
{
	//const static int DPI = 10;

	sf::RenderWindow window;
	Robot robotD;
	Robot robotA;
	Obstacle obstacle;

	Scene();

	void Update();
};