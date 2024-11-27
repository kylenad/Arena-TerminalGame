#include<iostream>
#include <list>
#include <array>
#include <random>
#include "../include/gameClass.h"
#include "../include/playerStats.h"
#include "../include/enemies/murderingFarmhand.h"
#include "../include/game.h"


void createCharacter(gameClass& myclass, playerStats& mystats) {
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


void encounterOne(playerStats& mystats, murderingFarmhand enemyStats) {
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


int main () {

    Game game;
    game.welcomeInfo();

    game.introStory();



    

    /*
    std::cout << "Arena" << '\n' << "Produced By - Kyle Nadeau" << '\n';
    std::cout << '\n' << "Start new game? ";
    std::string reply;
    std::cin >> reply;
    gameClass myclass;
    playerStats mystats;
    if(reply == "Yes" || reply == "yes") {
        createCharacter(myclass, mystats);
    } else if(reply == "No" || reply == "no") {
        std::cout << "Closing app..." << '\n';
        return 0;

    }

    

    std::cout << "You, a " << myclass.getClass() << ", have been captured long ago, forgotten, and abandonded in the city dungeon. "
                            << "Luckily for you (some added text sarcasam), the new arena construction has concluded. " 
                            << "You have been thrown in to the tunnels which house the contestants. "
                            << "The winner of the tournament will be granted pardon and the riches of kings. " 
                            << "Who knows what will be thrown at you along the way... " << '\n'
                            << '\n' <<  "Or what you may uncover..." << '\n';

    std::cout << '\n' << "Begin fight against Murdering Farmhand?" << '\n';
    std::cin >> reply;
    if(reply == "Yes" || reply == "yes") {
        murderingFarmhand enemyStats;
        encounterOne(mystats, enemyStats);
    } else if( reply == "No" || reply == "no") {
        std::cout << '\n' << "Cowards way out.... game over" << '\n';
        return 0;
    }

    */


    return 0;
}













//Compile line
// g++ -I include src/main.cpp src/gameClass.cpp  src/game.cpp -o adventure -std=c++20