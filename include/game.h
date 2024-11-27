#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {


    public:
        //Game();
        //virtual ~Game();

        //Operators

        //Functions
        void welcomeInfo();
        void introStory();
        void mainMenue();

        //Accessors

        //Modifiers

    private:
        int choice;
        bool playing;

};

#endif //GAME_H