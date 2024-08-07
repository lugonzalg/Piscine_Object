#pragma once

#include <iostream>

#include "shape.hpp"

class Rectangle : public Shape {

    public:

        Rectangle(float sideA, float sideB) :
            _sideA(sideA), _sideB(sideB) {

                std::cout << "\n[RECTANGLE] - constructor called\n";
                std::cout << "   + sideA: " << sideA << std::endl;
                std::cout << "   + sideB: " << sideB << "\n\n";
            }
        
        ~Rectangle() {}

        float area() const {
            return this->_sideA * this->_sideB;
        }

        float perimeter() const {
            return (this->_sideA * 2) + (this->_sideB * 2);
        }

    private:
        
        float _sideA;
        float _sideB;

};