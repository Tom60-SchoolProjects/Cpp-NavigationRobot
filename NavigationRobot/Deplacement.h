#pragma once

#include <SFML/Graphics.hpp>
#include "Robot.h";

void deplacerRobot(Robot, sf::Vector2f);

void calculVecteur(sf::Vector2f, sf::Vector2f);

void calculVitesse(sf::Vector2f, sf::Vector2f);