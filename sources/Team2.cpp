//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "Team2.hpp"

namespace ariel{
    Team2::Team2() : Team(){}
    Team2::Team2(Character *leader) : Team(leader){}

    void Team2::add(Character * member) {
        if (member->isInTeam())
            throw runtime_error("Member is already assigned to a team");
        if (members.size() < 10) {
            member->assignToTeam();
            members.push_back(member);
        } else
            throw runtime_error("Team is full !");
    }
}