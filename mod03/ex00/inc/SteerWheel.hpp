#pragma once

#include <iostream>

#include "DAE.hpp"

class SteerWheel {
    public:

        SteerWheel(DAE* dae) : _dae(dae) {
            std::cout << "[STEER-WHEEL] - constructor called\n";
            std::cout << *this;
        }

        ~SteerWheel() {
            std::cout << "[STEER-WHEEL] - destructor called\n";
        }

        void turn(float angle) {
            std::cout << "[STEER-WHEEL] - turn with an angle of: " << angle << std::endl;
            this->_dae->use(angle);
        }

        friend std::ostream& operator << (std::ostream& os, const SteerWheel& sw) {
            (void)sw;
            os << "[STEER-WHEEL]:\n   + ";
            os << sw._dae;
            return os;
        }

    private:
        DAE* _dae;

};