#include "../include/game.h"

void Game::welcomeInfo() {
    std::cout << "Arena" << '\n' << "Produced By - Kyle Nadeau" << '\n';
    std::cout << '\n' << "Start new game?" << std::endl;
    std::cout << "0: Yes" << std::endl;
    std::cout << "1: No" << std::endl;

    int reply;
    std::cout << "Reply: ";
    std::cin >> reply;
    
    switch (reply) {
        case 0:
            break;
        case 1:
            std::cout << "What are you here for then??" << std::endl;
        default:
            std::cout << "Invalid choice, maybe pay more attention next time" << std::endl;
    }

}

void Game::introStory() {
    std::cout << "You have been captured long ago, forgotten, and abandonded in the city dungeon. " << std::endl
                << "Luckily for you (some added text sarcasam), the new arena construction has concluded. " << std::endl
                << "You have been thrown in to the tunnels which house the contestants. " << std::endl
                << "The winner of the tournament will be granted pardon and the riches of kings. " << std::endl
                << "Who knows what will be thrown at you along the way... " << std::endl
                << '\n' <<  "Or what you may uncover..." << std::endl;

}

void Game::createCharacter(gameClass& myclass, playerStats& mystats) {
    std::cout << '\n' << "Select Class:" << '\n';

    myclass.showClasses();
    std::string classSelection;
    std::cout << '\n' << "Enter Class Name: ";
    std::cin >> classSelection;
    // Sets character class
    myclass.setClass(classSelection);
    std::cout << '\n' << "You are a " << classSelection << '\n' << '\n';
    mystats.displayStats();
    
}

void Game::encounterOne(playerStats& mystats, murderingFarmhand enemyStats) {
    //Used for percentage attack will hit
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<>dis(1, 100); 

    //Calculate players accuracy with luck bonus
    int playerAccuracyTotal = static_cast<int>(ceil(mystats.accuracy + (mystats.accuracy * mystats.luck/10.0)));
    int enemyAccuracyTotal = static_cast<int>(ceil(enemyStats.accuracy + (enemyStats.accuracy * enemyStats.luck/10.0)));

    if(mystats.agility > enemyStats.agility) {
        while(enemyStats.health > 0 && mystats.health > 0) {
            std::cout << "Your move" << '\n';
            std::string moveOption;
            std::cin >> moveOption;
            if(moveOption == "Attack") {
                int hitroll = dis(gen);
                if(hitroll <= playerAccuracyTotal) {
                    enemyStats.health = enemyStats.health - mystats.blade;
                    std::cout << "Hit!! " << mystats.blade << " damage dealt." << '\n'
                                << "Murdering Farmhand has " << enemyStats.health << " remaining" << '\n';
                } else {
                    std::cout << "Your attack missed..." << '\n';
                }

            }
            
            int hitroll2 = dis(gen);
            if(hitroll2 <= enemyAccuracyTotal) {
                mystats.health = mystats.health - enemyStats.blade;
                std::cout << "Enemy strikes you for " << enemyStats.blade << " points of damage" << '\n'
                            << "You have " << mystats.health << " health remaining" << '\n';
            } else {
                std::cout << "You dodged the enemy attack." << '\n';
            }

        }
        

    } else {
        while(enemyStats.health > 0 || mystats.health > 0) {
        }
    }
}