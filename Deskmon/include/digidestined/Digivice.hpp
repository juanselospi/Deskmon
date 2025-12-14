#pragma once

#include "digicode/Digicore.hpp"
#include "digiworld/GorimonGlass.hpp"
#include "digicode/Digishell.hpp"
#include "behavior/Movement.hpp" 
#include "behavior/Idle.hpp"

class Digivice {
private:
    GorimonGlass window;
    Digicore digicore;
    Digishell digishell;
    Movement movement;
    Idle idle;
    bool busy;

    sf::Event event;
    sf::Clock clock;

    void start();
    void update(float deltaTime);
    void render();
public:
    Digivice();
    ~Digivice();

    void run();
};