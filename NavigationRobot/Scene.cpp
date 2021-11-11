#include "Scene.h";

sf::RenderWindow ;

Scene::Scene()
	:window(sf::VideoMode(420, 420), "Navigation Robot")
{ }

void Scene::Update()
{
	window.clear(sf::Color::Color(242, 242, 242));
	window.draw(robotD.getShape());
	window.draw(robotA.getShape());
	window.draw(obstacle.getShape(), 2, sf::Lines);
	window.display();
}