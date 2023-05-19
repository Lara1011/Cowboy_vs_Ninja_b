//
// Created by Lara Abu Hamad on 5/18/23.
//

#ifndef COWBOY_VS_NINJA_B_COWBOY_HPP
#define COWBOY_VS_NINJA_B_COWBOY_HPP


#include "Character.hpp"
#include "Point.hpp"

namespace ariel{
class Cowboy : public Character {
private:
    int bullets;

public:
    Cowboy();

    Cowboy(string name, Point location);

    void shoot(Character *other);

    bool hasboolets();

    void reload();

    string print();

};

}


#endif //COWBOY_VS_NINJA_B_COWBOY_HPP
