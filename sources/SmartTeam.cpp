//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "SmartTeam.hpp"

namespace ariel {
    SmartTeam::SmartTeam() : Team() {}

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    // Attack the weakest enemy from each member of the attacking team
    void SmartTeam::attack(Team* enemyTeam) {
        if (enemyTeam == nullptr)
            throw invalid_argument("Enemy team is null!");
        if (this == enemyTeam)
            throw runtime_error("Team can't attack itself!");
        if (stillAlive() == 0)
            throw runtime_error("Attacker team has no living attackers!");
        if (enemyTeam->stillAlive() == 0)
            throw runtime_error("Enemy team has no living attackers!");

        if (!getLeader()->isAlive()) {
            Character* closestCharacter = chooseNewLeader();
            if (closestCharacter != nullptr) {
                setLeader(closestCharacter);
            } else {
                cout << "The attacking team has no living members." << endl;
                return;
            }
        }

        unordered_set<Character*> chosenTargets;

        for (Character* member : getMembers()) {
            if (member->isAlive()) {
                Character* enemy = chooseWeakestEnemy(enemyTeam->getMembers(), chosenTargets);
                if (enemy != nullptr) {
                    if (auto* cowboy = dynamic_cast<Cowboy*>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(enemy);
                        } else {
                            cowboy->reload();
                        }
                    } else if (auto* ninja = dynamic_cast<Ninja*>(member)) {
                        if (ninja->distance(enemy) < 1.0) {
                            ninja->slash(enemy);
                        } else {
                            ninja->move(enemy);
                        }
                    }
                    chosenTargets.insert(enemy);
                }
            }
        }
    }

    Character* SmartTeam::chooseWeakestEnemy(const vector<Character*>& enemies, const unordered_set<Character*>& chosenTargets) {
        cout << "------------------- ENEMY TEAM --------------------" << endl;
        int minHealth = numeric_limits<int>::max();
        Character* weakestEnemy = nullptr;
        for (Character* enemy : enemies) {
            enemy->print();
            if (enemy->isAlive() && chosenTargets.find(enemy) == chosenTargets.end()) {
                int health = enemy->getHitPoints();
                if (health < minHealth) {
                    minHealth = health;
                    weakestEnemy = enemy;
                }
            }
        }
        return weakestEnemy;
    }
}