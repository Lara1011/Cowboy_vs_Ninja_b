//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

namespace ariel{
    Character::Character() : name("lara"), location(Point()), hitPoints(0), inTeam(false){}
    Character::Character(string name, Point location, int points) : name(name), location(location), hitPoints(points), inTeam(
            false){}

    double Character::distance(Character *other) {
        return this->location.distance(other->location);
    }

    string Character::getName() {
        return this->name;
    }

    Point Character::getLocation() {
        return this->location;
    }

    int Character::getHitPoints(){
        return this->hitPoints;
    }

    bool Character::isAlive() {
        if(this->hitPoints > 0)
            return true;
        return false;
    }

    void Character::hit(int points) {
        if(points < 0)
            throw invalid_argument("Points should be positive !");
        this->hitPoints -= points;
    }

    void Character::setLocation(Point loc) {
        this->location = loc;
    }

    bool Character::isInTeam() {
        return this->inTeam;
    }

    void Character::assignToTeam() {
        this->inTeam = true;
    }

    void Character::print() {
        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this)) {
            std::cout << cowboy->print();
        } else if (Ninja *ninja = dynamic_cast<Ninja *>(this)) {
            std::cout << ninja->print();
        }
    }
}