#include <iostream>

#include "Eigen/Dense"

#include "SFML/Graphics/CircleShape.hpp"

#include "graphics/Window.h"
#include "world/Cube.h"

//NOTE: z-axis is positive into the screen

int main()
{
	Eigen::RowVector3f pos(200.0f, 250.0f, 0.0f);
	Cube cube(pos);
	cube.scale(200.0f);
	cube.rotateY(45);
	cube.rotateZ(45);
	cube.rotateX(45);

	Window window(Frame(600, 400), "SFML works!");

	window.addToDraw(&cube);

	window.start();

	return 0;
}