//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Team.hpp"
#include <unordered_set>

namespace ariel {
    Team::Team() {
        leader = new Character();
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
            members = sortBasedOnType();
        } else
            throw runtime_error("Team is full !");
    }

    void Team::attack(Team *enemyTeam) {
        if (enemyTeam == nullptr)
            throw invalid_argument("Team is null !");
        if (this == enemyTeam)
            throw runtime_error("Team can't attack itself !");
        if (stillAlive() == 0)
            throw runtime_error("Attacker team has no living attackers !");
        if (enemyTeam->stillAlive() == 0)
            throw runtime_error("Enemy team has no living attackers !");
        if (!leader->isAlive()) {
            Character *closestCharacter = chooseNewLeader();
            if (closestCharacter != nullptr) {
                leader = closestCharacter;
            } else {
                std::cout << "The attacking team has no living members." << endl;
                return;
            }
        }

        Character *enemy = chooseEnemy(enemyTeam->members);
        for (Character *member: members) {
            if (enemy != nullptr) {
                if (member->isAlive() && enemy->isAlive()) {
                    if (auto *cowboy = dynamic_cast<Cowboy *>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(enemy);
                        } else {
                            cowboy->reload();
                        }
                    }
                    if (auto *ninja = dynamic_cast<Ninja *>(member)) {
                        if (ninja->distance(enemy) < 1.0) {
                            ninja->slash(enemy);
                        } else {
                            ninja->move(enemy);
                        }
                    }

                }
            } else {
                cout<< " ---------------------------------- NO LIVING CHARACTERS LEFT IN THE TEAMS ---------------------------------------" << endl;
                return;
            }
            if (!enemy->isAlive())
                enemy = chooseEnemy(enemyTeam->members);
        }
    }

    int Team::stillAlive() {
        int alive = 0;
        for (Character *member: members)
            if (member->isAlive())
                alive++;
        return alive;
    }

    void Team::print() {
        for (Character *member: members) {
            member->print();
        }
    }

    Character *Team::chooseNewLeader() {
        double minDis = MAXFLOAT;
        Character *newLeader = nullptr;
        for (Character *member: members) {
            double dis = leader->distance(member);
            if (dis < minDis && leader != member && member->isAlive()) {
                minDis = dis;
                newLeader = member;
            }
        }
        return newLeader;
    }

    Character *Team::chooseEnemy(const vector<ariel::Character *> &enemies) {
        double minDis = MAXFLOAT;
        Character *newEnemy = nullptr;
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

    void Team::addMember(Character *member) {
        members.push_back(member);
    }

    void Team::setLeader(Character *newLeader) {
        leader = newLeader;
    }

    Character *Team::getLeader() {
        return leader;
    }

    vector<Character *> Team::sortBasedOnType() {
        vector<Character *> sortedMembers = members;
        sort(sortedMembers.begin(), sortedMembers.end(), [](Character *a, Character *b) {
            if (dynamic_cast<Cowboy *>(a) && dynamic_cast<Ninja *>(b)) {
                return true;
            } else {
                return false;
            }
        });
        return sortedMembers;
    }

}