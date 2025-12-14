#include "behavior/Idle.hpp"

constexpr int LOW_RANDOM = 1;
constexpr int HIGH_RANDOM = 10;

Idle::Idle(): gen(rd()), distrib(LOW_RANDOM, HIGH_RANDOM) {}

void Idle::currentWindowBorders(GorimonGlass& window) {
    stageTop = window.getWindowCoord("top");
    stageBottom = window.getTaskbarCoord("bottom");
    stageLeft = window.getWindowCoord("left");
    stageRight = window.getWindowCoord("right");
}

void Idle::Wander(Movement& movement, const std::string& digimonKey, Digishell& digishell, float deltaTime, bool& busy) {
    if(!isWandering) {
        // Generar 1 número aleatorio entre 1 y 10
        int randInt = distrib(gen);
        wanderTimer = distrib(gen);

        if(randInt < 3) {
            movement.moveTo("east");
            digishell.faceTo(digimonKey, "east");
            digishell.makePose(digimonKey, "walk");
        } else if(randInt > 3) {
            movement.moveTo("west");
            digishell.faceTo(digimonKey, "west");
            digishell.makePose(digimonKey, "walk");
        } else {
            movement.halt(digimonKey);
            digishell.makePose(digimonKey, "idle");
        }
        isWandering = true;
    }
    
    wanderTimer -= deltaTime;
    updateAll(movement, digimonKey, digishell, deltaTime);

    if(wanderTimer <= 0.f) {
        isWandering = false;
        busy = true;
    }
}

void Idle::updateAll(Movement& movement, const std::string& digimonKey, Digishell& digishell, float deltaTime) {
    if(digishell.whereAmI(digimonKey).x < stageLeft) {
        movement.moveTo("east");
        digishell.faceTo(digimonKey, "east");
    } else if(digishell.whereAmI(digimonKey).x > stageRight) {
        movement.moveTo("west");
        digishell.faceTo(digimonKey, "west");
    }
    movement.placeAllAt(digimonKey, digishell, deltaTime);
    digishell.animatePose(digimonKey, deltaTime);
}

Idle::~Idle() {}