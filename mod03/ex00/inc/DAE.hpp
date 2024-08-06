#pragma once

#include <iostream>

#include "Direction.hpp"

class DAE {

    public:

        DAE() {
            std::cout << "[DAE] - constructor called\n";
        }

        ~DAE() {
            std::cout << "[DAE] - destructor called\n";
        }

        void use(float angle) {
            std::cout << "[DAE] - turn with an angle of: " << angle << std::endl;
            this->_direction->turn(angle);
        }

        friend std::ostream& operator << (std::ostream& os, const DAE& dae) {
            os << "[DAE]:\n";
            os << "   + force: " << dae._force;
            os << "\n   + " << dae._direction;
            return os;
        }

    private:
        float _force;
        Direction* _direction;
};