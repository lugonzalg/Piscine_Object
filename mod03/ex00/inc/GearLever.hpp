#pragma once

#include <iostream>

#include "Gear.hpp"

class GearLever {

    public:

        static int UP;
        static int DOWN;
        static int REVERSE;

        GearLever() : _level(1) {
            std::cout << "[GEAR-LEVER] - constructor called\n";
            std::cout << *this;
        }

        ~GearLever() {
            std::cout << "[GEAR-LEVER] - destructor called\n";
        }

        void change(int mode) {

            if (mode == GearLever::REVERSE) {
                this->_level = 0;
                std::cout << "[GEAR-LEVER] - Gear level to: " << this->_level << " - REVERSE\n";
                return ;
            }

            if ((this->_level == 6 and mode == GearLever::UP)
                or (this->_level == 1 and mode == GearLever::DOWN))
                return ;

            this->_level += mode;
            if (mode == GearLever::UP)
                std::cout << "[GEAR-LEVER] - Gear level increased to: " << this->_level << std::endl;
            else
                std::cout << "[GEAR-LEVER] - Gear level decreased to: " << this->_level << std::endl;
        }

        Gear* activeGear() {
            return &this->_gears[this->_level];
        }

        friend std::ostream& operator << (std::ostream& os, const GearLever& gl) {

            os << "[GEAR-LEVER]:\n";
            os << "   + level: " << gl._level << std::endl;
            for (size_t idx = 0; idx < 7; idx++)
                std::cout << "   + " << gl._gears[idx];
            return os;
        }

    private:

        int _level;
        Gear _gears[7];

};

int GearLever::UP = 1;
int GearLever::DOWN = -1;
int GearLever::REVERSE = 0;