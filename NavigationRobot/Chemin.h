#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Robot.h"
#include "Obstacle.h"
#include "Point.h"
#include "Droite.h"

//bool cheminDirectPossible(Droite, Droite, Obstacle);

//Droite equationDeDroit(Point, Point);

//int calculDistance(Point, Point);

std::vector<Point> calculCheminOptimal(Point, Point, Obstacle);