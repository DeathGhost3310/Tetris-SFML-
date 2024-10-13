#ifndef VISUALIZER_H
#define VISUALIZER_H



#include "SFML/Graphics.hpp"

#include <memory>
#include <string>

#include "headers.h"
#include "map.h"

#pragma once


class Visualizer
{

public:
	Visualizer(std::shared_ptr<sf::RenderWindow> window, float fps, std::shared_ptr<Map> map);
	
	void update();
	bool isOpen();
private:
	float m_fps;
	
	void map_render();

	float indent_x = 762.f; //отсутп

	std::shared_ptr<sf::RenderWindow> m_window;

	std::shared_ptr<Map> m_map;

	sf::RectangleShape m_rect;
};

#endif