#include "visualizer.h"


Visualizer::Visualizer(std::shared_ptr<sf::RenderWindow> window, float fps, std::shared_ptr<Map> map) 
	: m_window(window), m_fps(fps), m_map(map)
{

}



void Visualizer::map_render() {
	
	for (int x = 0;x < 10;x++) {
		for (int y = 0;y < 20;y++) {
			if (m_map.get()->checkSquareFill(Coord{x, y})) {
				m_rect.setFillColor(sf::Color::Red);
			}
			else {
				m_rect.setFillColor(sf::Color::Black);
			}
			
			m_rect.setPosition((RES * x) + indent_x, y * RES );
			m_window.get()->draw(m_rect);
		}
	}

}


bool Visualizer::isOpen() {
	if (m_window.get()->isOpen()) {
		return true;
	}
	else {
		return false;
	}
}

void Visualizer::update() {
	m_window.get()->clear(sf::Color::Green);

	map_render();

	m_window.get()->display();
	sf::sleep(sf::milliseconds(1000.f / m_fps));

}