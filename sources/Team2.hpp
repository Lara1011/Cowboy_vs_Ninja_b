//
// Created by Lara Abu Hamad on 5/18/23.
//

#ifndef COWBOY_VS_NINJA_B_TEAM2_HPP
#define COWBOY_VS_NINJA_B_TEAM2_HPP


#include "Team.hpp"

namespace ariel{
    class Team2 : public Team {
    public:
        Team2();
        Team2(Character* leader);
        void add(Character* member) override;
    };
}


#endif //COWBOY_VS_NINJA_B_TEAM2_HPP
