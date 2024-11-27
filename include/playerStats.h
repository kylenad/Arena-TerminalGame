#ifndef PLAYER_STATS_H
#define PLAYER_STATS_H
#include <iostream>

class playerStats {
    public:
        int health = 100;
        int protection = 4;
        int agility = 3;
        int blade = 4;
        int blunt = 1;
        int range = 2;
        int magic = 3;
        int alchemy = 2;
        int accuracy = 50;
        int luck = 1;

        void displayStats() {
            std::cout << "Health: " << health << ", Protection: " << protection << '\n'
                        << "Agility: " << agility << ", Blade: " << blade << '\n'
                        << "Blunt: " << blunt << ", Range: " << range << '\n'
                        << "Magic: " << magic << ", Alchemy: " << alchemy << '\n'
                        << "Luck: " << luck << '\n';
        }


    private:


};

#endif //PLAYER_STATS_H