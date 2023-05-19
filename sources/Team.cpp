//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Team.hpp"
#include <unordered_set>

using namespace std;

namespace ariel {
    Team::Team() {
        Character ch = Character();
        this->leader = &ch;
        leader->assignToTeam();
    }

    Team::Team(Character *leader) : leader(leader) {
        if (leader->isInTeam())
            throw runtime_error("Leader is already assigned to a team");
        leader->assignToTeam();
        members.push_back(leader);
    }


    Team::~Team() {
        for (Character *member: members) {
            delete member;
        }
    }


    void Team::add(Character *member) {
        if (member->isInTeam())
            throw runtime_error("Member is already assigned to a team");
        if (members.size() < 10) {
            member->assignToTeam();
            members.push_back(member);
        } else
            throw runtime_error("Team is full !");
    }

    void Team::attack(Team *enemyTeam) {
        if (enemyTeam == nullptr)
            throw invalid_argument("Team is null !");
        members = sortBasedOnType();
        if (!leader->isAlive()) {
            Character *closestCharacter = chooseNewLeader();
            if (closestCharacter != nullptr) {
                leader = closestCharacter;
            } else {
                std::cout << "The attacking team has no living members." << std::endl;
                return;
            }
        }

        while (stillAlive() > 0 && enemyTeam->stillAlive() > 0) {
            Character *target = chooseEnemy(enemyTeam->members);
            if (target != nullptr) {
                for (Character *member: members) {
                    if (member->isAlive()) {
                        if(!target->isAlive())
                            break;
                        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                            if (cowboy->hasboolets()) {
                                cowboy->shoot(target);
                            } else {
                                cowboy->reload();
                            }
                        }
                        if (Ninja *ninja = dynamic_cast<Ninja *>(member)) {
                            if (leader->getLocation().distance(target->getLocation()) <= 1.0) {
                                ninja->slash(target);
                            } else {
//                                if (member == leader)
//                                    chooseNewLeader();
                                ninja->move(target);
                            }
                        }
                    }
                }
            }
        }
//        std::cout << "The enemy team has no living members." <<
//                  std::endl;
    }

    int Team::stillAlive() {
        int alive = 0;
        for (Character *member: members)
            if (member->isAlive())
                alive++;
        return alive;
    }

    void Team::print() {
        members = sortBasedOnType();
        for (Character *member: members) {
            member->print();
        }
    }

    Character *Team::chooseNewLeader() {
        double minDis = MAXFLOAT;
        Character *newLeader = nullptr;
        for (Character *member: members) {
            double dis = leader->distance(member);
            if (dis < minDis && leader != member) {
                minDis = dis;
                newLeader = member;
            }
        }
        return newLeader;
    }

    Character *Team::chooseEnemy(vector<ariel::Character *> enemies) {
        double minDis = MAXFLOAT;
        Character *newEnemy;
        for (Character *enemy: enemies) {
            if (enemy->isAlive()) {
                double dis = leader->distance(enemy);
                if (dis < minDis) {
                    minDis = dis;
                    newEnemy = enemy;
                }
            }
        }
        return newEnemy;
    }

    vector<Character *> Team::getMembers() {
        return members;
    }

    vector<Character*> Team::sortBasedOnType() {
        vector<Character*> sortedMembers = members;
        std::sort(sortedMembers.begin(), sortedMembers.end(), [](Character* a, Character* b) {
            if (dynamic_cast<Cowboy*>(a) && dynamic_cast<Ninja*>(b)) {
                return true;
            } else {
                return false;
            }
        });
        return sortedMembers;
    }

}