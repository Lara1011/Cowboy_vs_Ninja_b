//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "SmartTeam.hpp"

namespace ariel {
    SmartTeam::SmartTeam() : Team() {}

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    // Attack the enemy with the highest damage potential from each member of the attacking team
    void SmartTeam::attack(Team *enemyTeam) {
        if (enemyTeam == nullptr)
            throw invalid_argument("Enemy team is null!");
        if (this == enemyTeam)
            throw runtime_error("Team can't attack itself!");
        if (stillAlive() == 0)
            throw runtime_error("Attacker team has no living attackers!");
        if (enemyTeam->stillAlive() == 0)
            throw runtime_error("Enemy team has no living attackers!");

        if (!getLeader()->isAlive()) {
            Character *closestCharacter = chooseNewLeader();
            if (closestCharacter != nullptr) {
                setLeader(closestCharacter);
            } else {
                cout << "The attacking team has no living members." << endl;
                return;
            }
        }

        Character *enemy = chooseWeakestEnemy(enemyTeam->getMembers());
        for (Character *member: getMembers()) {
            if (enemy != nullptr) {
                if (member->isAlive() && enemy->isAlive()) {
                    if (auto *cowboy = dynamic_cast<Cowboy *>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(enemy);
                        } else {
                            cowboy->reload();
                        }
                    } else if (auto *ninja = dynamic_cast<Ninja *>(member)) {
                        if (ninja->distance(enemy) < 1.0) {
                            ninja->slash(enemy);
                        } else {
                            ninja->move(enemy);
                        }
                    }
                }
            }
            if (!enemy->isAlive())
                enemy = chooseWeakestEnemy(enemyTeam->getMembers());
        }
    }

    Character *SmartTeam::chooseWeakestEnemy(const vector<Character *> &enemies) {
        int maxDamage = INT32_MAX;
        Character *highestDamageEnemy = nullptr;
        for (Character *enemy: enemies) {
            if (enemy->isAlive()) {
                int damage = enemy->getHitPoints();
                if (damage < maxDamage) {
                    maxDamage = damage;
                    highestDamageEnemy = enemy;
                }
            }
        }
        return highestDamageEnemy;
    }
}