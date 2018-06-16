#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

#include "Frame.h"

class Window : public sf::RenderWindow
{
private:
	const unsigned short m_fps, m_ups; //Frames per second and Updates per second
	const Frame m_frame;
	std::vector<sf::Drawable*> m_toDraw;
	//std::vector<Updatable*> m_toUpdate;
public:
	Window(const Frame& frame, const sf::String& name, const unsigned short& fps = 60, const unsigned short& ups = 60);

	inline const Frame& getFrame() const { return m_frame; }

	void addToDraw(sf::Drawable* drawable, unsigned int order = UINT_MAX); //Only specify order if you want to have it run nth
	//void addToUpdate(Updatable* updatable, unsigned int order = UINT_MAX); //Here too
	void start();
};