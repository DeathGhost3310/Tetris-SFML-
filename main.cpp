#include <SFML/Graphics.hpp>
#include <memory>

#include "map.h"
#include "visualizer.h"
#include "headers.h"
#include "square.h"

int main()
{
    std::shared_ptr<sf::RenderWindow> window(std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Tetris"));
    const float FPS = 10;

    std::shared_ptr<Map> m_map;
    m_map.get()->figureGenerate();
    
    std::shared_ptr<Visualizer> m_visual(std::make_shared<Visualizer>(window, FPS, m_map));

    while (m_visual.get()->isOpen()) {
        m_visual.get()->update();
    }

    return 0;
}


