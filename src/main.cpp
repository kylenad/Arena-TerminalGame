#include "../include/game.h"

int main () {

    Game game;
    game.welcomeInfo();

    game.introStory();

    gameClass myclass;
    playerStats mystats;
    game.createCharacter(myclass, mystats);

    murderingFarmhand enemyStats;
    game.encounterOne(mystats, enemyStats);


    return 0;
}













//Compile line
// g++ -I include src/main.cpp src/gameClass.cpp  src/game.cpp -o adventure -std=c++20