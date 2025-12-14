#include "behavior/Movement.hpp"

Movement::Movement() : position(0.f, 0.f), smoothPosition(0.f, 0.f), velocity(0.f, 0.f), speed(50.f), smoothing(40.f) {}


void Movement::syncSpawns(const std::string& digimonKey, Digishell& digishell) {
    position = digishell.whereAmI(digimonKey);
    smoothPosition = position; // importante para evitar saltos
}

void Movement::updateAll(float deltaTime) {
    position += velocity * deltaTime; // desplazamiento = velocidad * tiempo
}

void Movement::placeAllAt(const std::string& digimonKey, Digishell& digishell, float deltaTime) {
    updateAll(deltaTime);

    // Lerp visual (ultra smooth) hacia la posición lógica
    smoothPosition += (position - smoothPosition) * smoothing * deltaTime;
    digishell.spawnAt(digimonKey, smoothPosition.x, smoothPosition.y);
}

void Movement::halt(const std::string& digimonKey) {
    velocity = {0.f, 0.f};
}

void Movement::moveTo(const std::string& direction) {
    // Normalizamos la dirección para evitar problemas de mayúsculas/minúsculas
    std::string dirLower = direction;
    std::transform(dirLower.begin(), dirLower.end(), dirLower.begin(), ::tolower);

    // Configuramos velocidades para cada dirección
    if (dirLower == "north") {
        velocity = {0.f, -speed};
    } 
    else if (dirLower == "south") {
        velocity = {0.f, speed};
    }
    else if (dirLower == "east") {
        velocity = {speed, 0.f};
    }
    else if (dirLower == "west") {
        velocity = {-speed, 0.f};
    }
    else if (dirLower == "northeast") {
        velocity = {speed * 0.707f, -speed * 0.707f}; // 45° diagonal
    }
    else if (dirLower == "northwest") {
        velocity = {-speed * 0.707f, -speed * 0.707f};
    }
    else if (dirLower == "southeast") {
        velocity = {speed * 0.707f, speed * 0.707f};
    }
    else if (dirLower == "southwest") {
        velocity = {-speed * 0.707f, speed * 0.707f};
    }
    else {
        velocity = {0.f, 0.f}; // Dirección desconocida
    }
}

void Movement::jump(const std::string& direction) {
    // implementar depués
}

Movement::~Movement() {}