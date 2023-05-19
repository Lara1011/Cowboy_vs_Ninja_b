//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef CPP_HW4_CHARACTER_HPP
#define CPP_HW4_CHARACTER_HPP


#include "Point.hpp"

namespace ariel{
class Character {
private:
    string name;
    Point location;
    int hitPoints;
    bool inTeam;

public:
    Character();
    virtual ~Character() = default;
    Character(string name, Point location, int points);
    bool isAlive();
    double distance(Character* other);
    void hit(int points);
    string getName();
    Point getLocation();
    int getHitPoints();
    void setLocation(Point loc);
    bool isInTeam();
    void assignToTeam();
    void print();
};
}

#endif //CPP_HW4_CHARACTER_HPP
