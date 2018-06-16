#include "Window.h"

#include "SFML/Window/Event.hpp"

Window::Window(const Frame& frame, const sf::String& name, const unsigned short& fps, const unsigned short& ups)
	: sf::RenderWindow(sf::VideoMode(frame.getWidth(), frame.getHeight()), name), m_fps(fps), m_ups(ups), m_frame(frame)
{

}

void Window::addToDraw(sf::Drawable* drawable, unsigned int order)
{
	if (order >= m_toDraw.size()) m_toDraw.push_back(drawable);
	else m_toDraw.insert(m_toDraw.begin() + order, drawable);
}

void Window::start()
{
	setActive(true);

	clock_t time = std::clock();
	unsigned long ticks = 0;

	while (isOpen())
	{
		sf::Event event;
		while (pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				close();
				break;

			}
		}

		//Update ticks
		if (std::clock() - time >= CLOCKS_PER_SEC / m_ups)
		{
			time = std::clock();

			//m_camera.update();
			//for (Updatable* u : m_toUpdate) u->update(ticks);

			ticks++;
		}

		//Render ticks
		clear();

		draw(m_frame);
		for (sf::Drawable* d : m_toDraw) draw(*d);

		display();
	}
}