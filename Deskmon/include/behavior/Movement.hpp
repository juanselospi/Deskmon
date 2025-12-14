#pragma once

#include "lib/core_lib.hpp"
#include "lib/graphics_lib.hpp"
#include "digicode/Digishell.hpp"


class Movement {
private:
    sf::Vector2f position;
    sf::Vector2f smoothPosition;
    sf::Vector2f velocity;
    float speed; // volver vector y asignar velocidad por digimon
    float smoothing; // entre más alto, más suave pero más retrasado
public:
    Movement();
    ~Movement();

    void syncSpawns(const std::string& digimonKey, Digishell& digishell);
    void placeAllAt(const std::string& digimonKey, Digishell& digishell, float deltaTime); // modificar para mover todos los sprites
    void halt(const std::string& digimonKey);
    void updateAll(float deltaTime);
    void moveTo(const std::string& direction);
    void jump(const std::string& direction);
};