#pragma once

#include <SFML/Graphics.hpp>
#include "Robot.h"

bool cheminDirectPossible();

int calculDistance(sf::Vector2f, sf::Vector2f);

sf::Vector2f* calculCheminOptimal(Robot, Robot, Obstacle);