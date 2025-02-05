#pragma once

#include <cmath>

#include "shape.hpp"

class Circle : public Shape {

    public:

        Circle(float radious) : _radious(radious) {
            std::cout << "[CIRCLE] - constructor called\n";
            std::cout << "   + radious: " << radious << "\n\n";
        }

        ~Circle() {}

        float area() const {
            return M_PI * std::pow(this->_radious, 2);
        }

        float perimeter() const {
            return 2 * M_PI * this->_radious;
        }

    private:

        float _radious;

        Circle() {}
};