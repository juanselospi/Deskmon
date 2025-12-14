#include "digicode/Digishell.hpp"

constexpr int FRAME_WIDTH = 64;
constexpr int FRAME_HEIGHT = 64;

constexpr float ANIMATION_SPEED = 0.5f; // segundos entre cambios de frame

Digishell::Digishell() {}

void Digishell::loadDigishell(const std::string& filepath, const std::string& digimonKey) {
    sf::Texture texture;
    sf::Sprite sprite;

    if(!texture.loadFromFile((filepath))) return;

    textures[digimonKey] = std::move(texture);
    sprite.setTexture(textures[digimonKey]);
    sprites[digimonKey] = std::move(sprite);


    std::vector<std::pair<std::string, int>> animAction = {
        {"idle", 2},
        {"walk", 2},
        {"run", 2},
        {"train", 2},
        {"greet", 1},
        {"sleep", 1},
        {"attack", 1},
        {"jump", 1}
    };

    int frameIndex = 0;
    for(const auto& [animName, count] : animAction) {
        std::vector<sf::IntRect> frames;
        for(int i = 0; i < count; ++i) {
            frames.emplace_back(FRAME_WIDTH * frameIndex, 0, FRAME_WIDTH, FRAME_HEIGHT);
            ++frameIndex;
        }
        animations[digimonKey][animName] = std::move(frames);
    }
}

void Digishell::clearDigishell(const std::string& digimonKey) {
    if(animations.count(digimonKey)) animations.erase(digimonKey);
    if(textures.count(digimonKey)) textures.erase(digimonKey);
    if(sprites.count(digimonKey)) sprites.erase(digimonKey);
}

sf::Sprite& Digishell::getDigishell(const std::string& digimonKey) {
    return sprites.at(digimonKey);
}

void Digishell::makePose(const std::string& digimonKey, const std::string& animKey) {
    if(animations.count(digimonKey) == 0 || animations.at(digimonKey).count(animKey) == 0) return;

    size_t frameIndex = 0;
    const auto& frames = animations.at(digimonKey).at(animKey);
    if(frameIndex >= 0 && frameIndex < frames.size()) {
        sprites[digimonKey].setTextureRect(frames[frameIndex]);
    }
    // ⬇ Guardar estado de animación
    currentPose[digimonKey] = animKey;
    currentFrame[digimonKey] = frameIndex;
    poseTimers[digimonKey] = 0.f;
}

void Digishell::animatePose(const std::string& digimonKey, float deltaTime) {
    for(auto& [digimonKey, poseName] : currentPose) {
        auto& frames = animations[digimonKey][poseName];

        if(frames.size() < 2) {
            continue; // no seria break para salir del for?
        }

        poseTimers[digimonKey] += deltaTime;

        if(poseTimers[digimonKey] >= ANIMATION_SPEED) {
            poseTimers[digimonKey] = 0.f;

            // Alternar frame (0 <-> 1)
            size_t nextFrame = 1 - currentFrame[digimonKey];
            currentFrame[digimonKey] = nextFrame;
            sprites[digimonKey].setTextureRect(frames[nextFrame]);
        }
    }
}

void Digishell::faceTo(const std::string& digimonKey, const std::string& direction) {
    if (sprites.count(digimonKey) == 0) return;

    sf::Sprite& sprite = sprites[digimonKey];

    // Volteamos horizontalmente según la dirección
    if (direction == "west") {
        sprite.setScale(1.f, 1.f); // Normal, mirando a la izquierda
        sprite.setOrigin(0.f, 0.f); // Restaurar el origen a la esquina superior izquierda
    } else if (direction == "east") {
        sprite.setScale(-1.f, 1.f); // Volteado, mirando a la derecha

        // Ajustar el origen al borde derecho para que no desaparezca
        sprite.setOrigin(FRAME_WIDTH, 0.f);
    }
}

void Digishell::spawnAt(const std::string& digimonKey, float posX, float posY) {
    sf::Sprite& sprite = sprites[digimonKey];

    // Origen en el centro inferior del sprite
    sprite.setOrigin(FRAME_WIDTH / 2, FRAME_HEIGHT);
    sprites[digimonKey].setPosition(posX, posY);
}

sf::Vector2f Digishell::whereAmI(const std::string& digimonKey) {
    return sprites[digimonKey].getPosition();
}

Digishell::~Digishell() {}