//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "Team2.hpp"

namespace ariel{
    Team2::Team2() : Team(){}
    Team2::Team2(Character *leader) : Team(leader){}

//    void Team2::attack(Team *enemyTeam) {
//        if(enemyTeam == nullptr)
//            throw invalid_argument("Team is null !");
//        if (!leader->isAlive()) {
//            // Select a new leader as the closest living character
//            Character *closestCharacter = nullptr;
//            float closestDistance = std::numeric_limits<float>::max();
//
//            for (Character *member: members) {
//                if (member != leader && member->isAlive()) {
//                    float distance = leader->getLocation().distance(member->getLocation());
//                    if (distance < closestDistance) {
//                        closestDistance = distance;
//                        closestCharacter = member;
//                    }
//                }
//            }
//
//            if (closestCharacter != nullptr) {
//                leader = closestCharacter;
//            } else {
//                std::cout << "The attacking team has no living members." << std::endl;
//                return;
//            }
//        }
//
//        Character *target = nullptr;
//        float closestDistance = std::numeric_limits<float>::max();
//
//        // Find the closest living character from the enemy team
//        for (Character *enemy: enemyTeam->getMembers()) {
//            if (enemy->isAlive()) {
//                float distance = leader->getLocation().distance(enemy->getLocation());
//                if (distance < closestDistance) {
//                    closestDistance = distance;
//                    target = enemy;
//                }
//            }
//        }
//
//        if (target != nullptr) {
//            for (Character *member: members) {
//                if (member->isAlive()) {
//                    Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
//                    if (cowboy) {
//                        if (cowboy->hasboolets()) {
//                            cowboy->shoot(target);
//                        } else {
//                            cowboy->reload();
//                        }
//                    }
//                    Ninja *ninja = dynamic_cast<Ninja *>(member);
//                    if (ninja) {
//                        if (leader->getLocation().distance(target->getLocation()) <= 1.0) {
//                            ninja->slash(target);
//                        } else {
//                            if(member == leader)
//                                chooseNewLeader();
//                            ninja->move(target);
//                        }
//                    }
//                }
//            }
//        } else {
//            std::cout << "The enemy team has no living members." <<
//                      std::endl;
//        }
//    }
}