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

        Character *enemy = chooseHighestDamageEnemy(enemyTeam->getMembers());
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
                enemy = chooseHighestDamageEnemy(enemyTeam->getMembers());
        }
    }

    Character *SmartTeam::chooseHighestDamageEnemy(const vector<Character *> &enemies) {
        int highestDamage = 0;
        Character *highestDamageEnemy = nullptr;
        for (Character *enemy: enemies) {
            if (enemy->isAlive()) {
                int damage = calculateDamage(enemy);
                if (damage > highestDamage) {
                    highestDamage = damage;
                    highestDamageEnemy = enemy;
                }
            }
        }
        return highestDamageEnemy;
    }

    int SmartTeam::calculateDamage(Character *enemy) {
        int damage = 0;
        for (Character *attacker: getMembers()) {
            if (attacker->isAlive()) {
                if (auto *cowboy = dynamic_cast<Cowboy *>(attacker)) {
                    if (cowboy->hasboolets()) {
                        damage += 10;
                    }
                } else if (auto *ninja = dynamic_cast<Ninja *>(attacker)) {
                    if (ninja->distance(enemy) < 1.0) {
                        damage += 40;
                    }
                }
            }
        }
        return damage;
    }
}