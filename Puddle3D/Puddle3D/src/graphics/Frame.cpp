#include "Frame.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

Frame::Frame(const unsigned int& width, const unsigned int& height)
	: m_width(width), m_height(height) {}

Frame::~Frame() {}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape rect(sf::Vector2f(m_width, m_height));
	rect.setFillColor(sf::Color::Black);
	target.draw(rect, states);
}