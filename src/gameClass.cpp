#include "../include/gameClass.h"

void gameClass::showClasses () {
    for(int i = 0; i < classList.size(); i++) {
                std::cout << classList[i] << '\n';
            }
}

void gameClass::setClass (const std::string& newClass) {
    yourClass = newClass;
}

std::string gameClass::getClass () {
    return yourClass;
}