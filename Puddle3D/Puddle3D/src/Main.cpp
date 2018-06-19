#include <iostream>

#include "Eigen/Dense"

#include "SFML/Graphics/CircleShape.hpp"

#include "graphics/Window.h"

//NOTE: z-axis is positive into the screen

int main()
{
	Eigen::MatrixXd m(2, 2);
	m(0, 0) = 3;
	m(1, 0) = 2.5;
	m(0, 1) = -1;
	m(1, 1) = m(1, 0) + m(0, 1);
	std::cout << m << "\n";
	
	Window window(Frame(200, 200), "SFML works!");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.addToDraw(&shape);

	window.start();

	return 0;
}