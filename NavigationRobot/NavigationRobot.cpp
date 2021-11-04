#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Robot.h"

Robot robot;
sf::RenderWindow window(sf::VideoMode(420, 420), "Casse-Briques");

int main()
{
	sf::Clock clock;

    std::cout << "Hello World!\n";

    robot.setPosition(10, 10);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					return 0;
			}
		}

		if (clock.getElapsedTime().asMilliseconds() > 10)
		{
			//update();
			clock.restart();
		}
	}
	window.close();
}