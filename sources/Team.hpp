//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <cmath>
#include <algorithm>

using namespace std;
namespace ariel {
    class Team {
    private:
        Character *leader;
        vector<Character *> members;
    public:
        Team();

        Team(Character *leader);

        void add(Character *member);

        void attack(Team *enemyTeam);

        int stillAlive();

        Character* chooseNewLeader();

        Character* chooseEnemy(const vector<Character*>& enemies);

        vector<Character *> getMembers();

        vector<Character*> sortBasedOnType();

        void setLeader(Character* newLeader);

        Character* getLeader();

        void addMember(Character* member);

        void print();

        ~Team();

        Team (Team&) = delete; // Copy Constructor.
        Team (Team&&) noexcept = delete; // Move Constructor.
        Team& operator = (const Team&) = delete; // Copy assignment operator.
        Team& operator = (Team&&) noexcept = delete; // Move assignment operator.
    };
}

#endif //CPP_HW4_TEAM_HPP
