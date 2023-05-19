//
// Created by Lara Abu Hamad on 5/18/23.
//

#include "SmartTeam.hpp"

namespace ariel {
    SmartTeam::SmartTeam() : Team() {}

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    void SmartTeam::attack(Team *enemyTeam) {
        if(enemyTeam == nullptr)
            throw invalid_argument("Team is null !");
        // Find the weakest enemy member and attack it
        Character *weakestEnemy = nullptr;
        int minHealth = INT_MAX;

        // Iterate over the enemy team's members
        vector<Character *> enemyMembers = enemyTeam->getMembers();
        for (Character *enemy: enemyMembers) {
            if (enemy->getHitPoints() < minHealth) {
                minHealth = enemy->getHitPoints();
                weakestEnemy = enemy;
            }
        }

        // Check if a weakest enemy was found
        if (weakestEnemy != nullptr) {
            // Attack the weakest enemy
            Cowboy *cowboy = dynamic_cast<Cowboy *>(leader);
            if (cowboy) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(weakestEnemy);
                } else {
                    cowboy->reload();
                }
            }
            Ninja *ninja = dynamic_cast<Ninja *>(leader);
            if (ninja) {
                if (leader->getLocation().distance(weakestEnemy->getLocation()) <= 1.0) {
                    ninja->slash(weakestEnemy);
                } else {
                    ninja->move(weakestEnemy);
                }
            }
        }
    }
}