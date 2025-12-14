#pragma once

#include "lib/core_lib.hpp"
#include "behavior/Movement.hpp"
#include "digicode/Digishell.hpp"
#include "digiworld/GorimonGlass.hpp"

class Idle {
private:
    float stageTop;
    float stageBottom;
    float stageLeft;
    float stageRight;

    bool isWandering = false;
    float wanderTimer;

    // Motor de números aleatorios
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
public:
    Idle();
    ~Idle();
    void currentWindowBorders(GorimonGlass& window);
    void Wander(Movement& movement, const std::string& digimonKey, Digishell& digishell, float deltaTime, bool& busy);
    void updateAll(Movement& movement, const std::string& digimonKey, Digishell& digishell, float deltaTime);
};