//
// Created by Lara Abu Hamad on 5/18/23.
//

#ifndef COWBOY_VS_NINJA_B_NINJA_HPP
#define COWBOY_VS_NINJA_B_NINJA_HPP


#include "Character.hpp"

namespace ariel{
    class Ninja : public Character{
    private:
        int speed;

    public:
        Ninja();
        Ninja(string name, Point location, int points, int speed);
        void move(Character* other);
        void slash(Character* other);
        string print();
    };
}


#endif //COWBOY_VS_NINJA_B_NINJA_HPP
