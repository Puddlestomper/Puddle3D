#include <SFML/Graphics.hpp>

#include "graphics/Window.h"

int main()
{
	Window window(Frame(200, 200), "SFML works!");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.addToDraw(&shape);

	window.start();

	return 0;
}