#pragma once

#include "SFML/Graphics/Drawable.hpp"

class Frame : public sf::Drawable
{
private:
	const unsigned int m_width, m_height;
public:
	Frame(const unsigned int& width, const unsigned int& height);
	virtual ~Frame();

	inline const unsigned int& getWidth() const { return m_width; }
	inline const unsigned int& getHeight() const { return m_height; }
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};