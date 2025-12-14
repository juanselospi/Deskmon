#pragma once

#include "lib/core_lib.hpp"

class Digicore {
private:
    // nominal attributes
    std::string name;
    std::string attribute; // Vaccine, Virus, Data, Free, Variable
    std::string stage; // Fresh, In-Training, Rookie, Champion, Ultimate, Mega
    std::string field; // Nature Spirits, Deep Savers, Nightmare Soldiers, Wind Guardians, Metal Empire, Virus Busters, Dragon's Roar, Jungle Troopers, etc...
    std::string armor; // Chrondigizoit, Chrome Digizoid, Black Digizoid, Blue Digizoid, Gold Digizoid, Obsidian Digizoid, Red Digizoid, Brown Digizoid, Cyplasium Digizoid 

    // pet attributes
    std::string happiness;
    std::string hunger;
    std::string energy;
    std::string mood; // Restless, Irritated, Lonely, Playful, Relaxed, 

    // stat attributes
    int lvl;
    int hp;
    int attack;
    int defense; // su multiplicador es el armor
    int speed;
    int weight; // afecta el salto

public:
    Digicore();
    ~Digicore();
};