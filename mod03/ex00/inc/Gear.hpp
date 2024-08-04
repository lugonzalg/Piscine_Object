#pragma once

#include <iostream>

class Gear {

    public:

        Gear() : _demultiplier(1) {
            std::cout << "[GEAR] - constructor called\n";
            std::cout << *this;
        }

        ~Gear() {
            std::cout << "[GEAR] - destructor called\n";
        }

        friend std::ostream& operator << (std::ostream& os, const Gear& gear) {
            os << "[GEAR] - demultiplier: " << gear._demultiplier << std::endl;
            return os;
        }

    private:
        int _demultiplier;
};