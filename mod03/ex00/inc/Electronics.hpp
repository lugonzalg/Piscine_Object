#pragma once

#include <iostream>

#include "DAE.hpp"

class Electronics {
    public:

        DAE dae;

        Electronics() {
            std::cout << "[ELECTRONICS] - constructor called\n";
        }

        ~Electronics() {
            std::cout << "[ELECTRONICS] - destructor called\n";
        }

        friend std::ostream& operator << (std::ostream& os, const Electronics& e) {
            os << "[ELECTRONICS]:\n";
            os << "   + " << e.dae;
            return os;
        }


};