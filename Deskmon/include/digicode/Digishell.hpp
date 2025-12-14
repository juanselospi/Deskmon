#pragma once

#include "lib/core_lib.hpp"
#include "lib/graphics_lib.hpp"

class Digishell {
private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<sf::IntRect>>> animations;
    std::unordered_map<std::string, sf::Sprite> sprites;

    std::unordered_map<std::string, std::string> currentPose;        // "idle", "walk", etc.
    std::unordered_map<std::string, size_t> currentFrame;            // frame actual (0 o 1)
    std::unordered_map<std::string, float> poseTimers;               // acumulador de tiempo                                    
public:
    Digishell();
    ~Digishell();

    void loadDigishell(const std::string& filepath, const std::string& digimonKey);
    void clearDigishell(const std::string& digimonKey);
    sf::Sprite& getDigishell(const std::string& digimonKey);
    void makePose(const std::string& digimonKey, const std::string& animKey);
    void animatePose(const std::string& digimonKey, float deltaTime);
    void faceTo(const std::string& digimonKey, const std::string& direction);
    void spawnAt(const std::string& digimonKey, float posX, float posY);
    sf::Vector2f whereAmI(const std::string& digimonKey);
};