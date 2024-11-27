#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "../include/gameClass.h"
#include "../include/playerStats.h"
#include "../include/enemies/murderingFarmhand.h"
#include <list>
#include <array>
#include <random>

class Game {


    public:
        //Game();
        //virtual ~Game();

        //Operators

        //Functions
        void welcomeInfo();
        void introStory();
        void createCharacter(gameClass& myclass, playerStats& mystats);
        void mainMenue();

        void encounterOne(playerStats& mystats, murderingFarmhand enemyStats);

        //Accessors

        //Modifiers

    private:
        int choice;
        bool playing;

};

#endif //GAME_H