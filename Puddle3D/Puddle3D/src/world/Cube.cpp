#include "Cube.h"

#include "SFML/Graphics/RenderTarget.hpp"

//#include <iostream>

Cube::Cube(const Eigen::RowVector3f& position, const Eigen::Matrix3f& transform)
	: Object3D(position, transform, 24)
{
	m_points = Eigen::Matrix<float, 8, 3>();
	m_points <<  0.5f,  0.5f,  0.5f,
				-0.5f,  0.5f,  0.5f,
				 0.5f, -0.5f,  0.5f,
				-0.5f, -0.5f,  0.5f,
				 0.5f,  0.5f, -0.5f,
				-0.5f,  0.5f, -0.5f,
				 0.5f, -0.5f, -0.5f,
				-0.5f, -0.5f, -0.5f;

	//std::cout << "Points:\n" << m_points << "\n";
	//std::cout << "Transform:\n" << m_transform << "\n";

	m_vertices.setPrimitiveType(sf::Quads);
	updateVArray();
}

//Still need to add proper projection onto camera
void Cube::updateVArray()
{
	Eigen::Matrix<float, 8, 3> vertices;
	vertices << m_position, m_position, m_position, m_position, m_position, m_position, m_position, m_position;
	vertices += m_points * m_transform;

	sf::Vector2f p1 = sf::Vector2f(vertices(0, 0), vertices(0, 1));
	sf::Vector2f p2 = sf::Vector2f(vertices(1, 0), vertices(1, 1));
	sf::Vector2f p3 = sf::Vector2f(vertices(2, 0), vertices(2, 1));
	sf::Vector2f p4 = sf::Vector2f(vertices(3, 0), vertices(3, 1));
	sf::Vector2f p5 = sf::Vector2f(vertices(4, 0), vertices(4, 1));
	sf::Vector2f p6 = sf::Vector2f(vertices(5, 0), vertices(5, 1));
	sf::Vector2f p7 = sf::Vector2f(vertices(6, 0), vertices(6, 1));
	sf::Vector2f p8 = sf::Vector2f(vertices(7, 0), vertices(7, 1));

	sf::Vertex* quad = &m_vertices[0];
	quad[0].position = p1;
	quad[1].position = p2;
	quad[2].position = p4;
	quad[3].position = p3;
	quad[0].color = sf::Color::Cyan;
	quad[1].color = sf::Color::Cyan;
	quad[2].color = sf::Color::Cyan;
	quad[3].color = sf::Color::Cyan;

	quad = &m_vertices[4];
	quad[0].position = p7;
	quad[1].position = p8;
	quad[2].position = p4;
	quad[3].position = p3;
	quad[0].color = sf::Color::Magenta;
	quad[1].color = sf::Color::Magenta;
	quad[2].color = sf::Color::Magenta;
	quad[3].color = sf::Color::Magenta;

	quad = &m_vertices[8];
	quad[0].position = p6;
	quad[1].position = p2;
	quad[2].position = p4;
	quad[3].position = p8;
	quad[0].color = sf::Color::Yellow;
	quad[1].color = sf::Color::Yellow;
	quad[2].color = sf::Color::Yellow;
	quad[3].color = sf::Color::Yellow;

	quad = &m_vertices[12];
	quad[0].position = p1;
	quad[1].position = p5;
	quad[2].position = p7;
	quad[3].position = p3;
	quad[0].color = sf::Color::White;
	quad[1].color = sf::Color::White;
	quad[2].color = sf::Color::White;
	quad[3].color = sf::Color::White;

	quad = &m_vertices[16];
	quad[0].position = p1;
	quad[1].position = p2;
	quad[2].position = p6;
	quad[3].position = p5;
	quad[0].color = sf::Color::Red;
	quad[1].color = sf::Color::Red;
	quad[2].color = sf::Color::Red;
	quad[3].color = sf::Color::Red;

	quad = &m_vertices[20];
	quad[0].position = p6;
	quad[1].position = p5;
	quad[2].position = p7;
	quad[3].position = p8;
	quad[0].color = sf::Color::Blue;
	quad[1].color = sf::Color::Blue;
	quad[2].color = sf::Color::Blue;
	quad[3].color = sf::Color::Blue;
}

void Cube::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_vertices, states);
}