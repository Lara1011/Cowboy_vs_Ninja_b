//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "Ninja.hpp"

using namespace std;

namespace ariel {
    Ninja::Ninja() : speed(4), Character() {}

    Ninja::Ninja(string name, Point location, int points, int speed) : speed(speed),
                                                                       Character(name, location, points) {}
    void Ninja::move(Character *other) {
        Point enemyLocation = other->getLocation();
        double distance = getLocation().distance(enemyLocation);
        double moveDistance = min(distance, static_cast<double>(speed));
        Point newLocation = getLocation().moveTowards(getLocation(), enemyLocation, moveDistance);
        setLocation(newLocation);
    }

    void Ninja::slash(Character *other) {
        if(this == other)
            throw runtime_error("Can't harm yourself !");
        if(!other->isAlive() || !isAlive())
            throw runtime_error("Character is already dead !");
        if (isAlive() && this->distance(other) < 1)
            other->hit(40);
    }

    string Ninja::print() {
        if (!isAlive())
            return "N- (" + this->getName() + ")";
        else
            return "N- " + this->getName() + ", Hit points: " + to_string(this->getHitPoints()) + ", Location: (" +
                   to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getX()) + ")\n";
    }
}