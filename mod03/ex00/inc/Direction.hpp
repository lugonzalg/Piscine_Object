#pragma once

#include <iostream>

#include "Wheel.hpp"

class Car;

class Direction {

    public:

        Direction() {
            std::cout << "[DIRECTION] - constructor called\n";
            std::cout << *this;
        }

        ~Direction() {
            std::cout << "[DIRECTION] - destructor called\n";
        }

        void turn(float angle) {
            std::cout << "[DIRECTION] - turn with an angle of: " << angle << std::endl;
        }

        friend std::ostream& operator << (std::ostream& os, const Direction& direction) {

            os << "[DIRECTION]:\n";

            for (size_t idx = 0; idx < 2; idx++) {
                os << "   + " << direction._wheels[idx];
            }
            return os;
        }

        friend Car;

    private:
        Wheel _wheels[2];
};