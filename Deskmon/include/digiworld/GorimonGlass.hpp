#pragma once

#include "lib/graphics_lib.hpp"
#include "utils/window_utils.hpp"

class GorimonGlass {
private:
    sf::RenderWindow window;
    bool visible;
public:
    GorimonGlass();
    ~GorimonGlass();

    void display();
    void clear();
    void close();
    bool isOpen() const;
    bool pollEvent(sf::Event& event);
    void draw(const sf::Sprite& digimon);
    int getTaskbarCoord(const std::string& position) const;
    int getWindowCoord(const std::string& position) const;
};