#pragma once

#include <iostream>

#include "LinkablePart.hpp"

class Pedal {


    public:
        Pedal() {
            std::cout << "[PEDAL] - constructor called\n";
        }

        ~Pedal() {
            std::cout << "[PEDAL] - destructor called\n";
        }

        friend std::ostream& operator << (std::ostream& os, const Pedal& p) {
            (void)p;
            os << "[PEDAL]:";
            return os;
        }

        void setTarget(LinkablePart* part) {
            this->_part = part;
        }

        void use(float pression) {
            this->_part->execute(pression);
        }

    private:

        LinkablePart *_part;

};