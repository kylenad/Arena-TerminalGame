#ifndef GAMECLASS_H
#define GAMECLASS_H
#include <iostream>
#include <array>
#include <list>

class gameClass {
    public:

        void setClass(const std::string& newClass);
        std::string getClass();
        void showClasses();


    private:
        std::string yourClass;
        std::array<std::string, 6> classList = {"Warrior","Mage", "Druid",
                                     "Knight", "Alchemist", "Archer"};

};
#endif //GAMECLASS_H