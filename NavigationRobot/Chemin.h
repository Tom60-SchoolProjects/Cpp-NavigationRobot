#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Robot.h"
#include "Obstacle.h"
#include "Point.h"

bool cheminDirectPossible();

int calculDistance(sf::Vector2f, sf::Vector2f);

sf::Vector2f* calculCheminOptimal(Robot, Robot, Obstacle);