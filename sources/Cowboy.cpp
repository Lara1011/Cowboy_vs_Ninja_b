//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy() : bullets(6), Character("lara", Point(), 110) {}

    Cowboy::Cowboy(string name, Point location) : bullets(6), Character(name, location, 110) {}

    string Cowboy::print() {
        if (!isAlive())
            return "C- (" + this->getName() + ")";
        else {
            return "C- " + this->getName() + ", Hit points: " + to_string(this->getHitPoints()) + ", Location: (" +
                    to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")\n";
        }
    }

    void Cowboy::reload() {
        if(!isAlive())
            throw runtime_error("Cowboy is dead !");
        this->bullets = 6;
    }

    void Cowboy::shoot(Character *other) {
        if(this == other)
            throw runtime_error("Can't harm yourself !");
        else if(!other->isAlive())
            throw runtime_error("Cowboy's enemy is already dead !");
        else if(!isAlive())
            throw runtime_error("Cowboy is already dead !");
        else if (isAlive() && hasboolets()) {
            this->bullets--;
            other->hit(10);
        }
    }

    bool Cowboy::hasboolets() {
        if (bullets > 0)
            return true;
        return false;
    }
}