#include "digidestined/Digivice.hpp"

Digivice::Digivice() : window() {}

void Digivice::start() {
    idle.currentWindowBorders(window);

    digishell.loadDigishell("assets/digishell/agumon_ex/Agumon.png", "Agumon");


    digishell.makePose("Agumon", "walk");
    digishell.spawnAt("Agumon", 700.f, window.getTaskbarCoord("top"));
    movement.syncSpawns("Agumon", digishell);

}

void Digivice::run() {
    start();

    while(window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        update(deltaTime);
        render();
    }

}

void Digivice::update(float deltaTime) {

    if(!busy) {
        idle.Wander(movement, "Agumon", digishell, deltaTime, busy);
    }

    busy = false;
}

void Digivice::render() {
    window.clear();
    window.draw(digishell.getDigishell("Agumon"));
    window.display();
}

Digivice::~Digivice() {}




// TO DO LIST:  arreglar que las poses de run en adelante no funcionan