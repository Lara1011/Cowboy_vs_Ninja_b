//
// Created by Lara Abu Hamad on 5/18/23.
//

#ifndef COWBOY_VS_NINJA_B_SMARTTEAM_HPP
#define COWBOY_VS_NINJA_B_SMARTTEAM_HPP


#include "Team.hpp"
#include <unordered_set>

namespace ariel{
    class SmartTeam : public Team {
    public:
        SmartTeam();
        SmartTeam(Character* leader);
        void attack(Team* enemyTeam);
        Character* chooseWeakestEnemy(const vector<Character*>& enemies);
    };
}


#endif //COWBOY_VS_NINJA_B_SMARTTEAM_HPP
