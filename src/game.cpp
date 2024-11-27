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