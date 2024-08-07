#pragma once

#include <iostream>
#include <cmath>

#include "shape.hpp"

class Triangle : public Shape {

    public:

        Triangle(float sideA, float sideB, float sideC) :
            _sideA(sideA), _sideB(sideB), _sideC(sideC) {
                std::cout << "[TRIANGLE] - constructor called\n";
                std::cout << "   + sideA: " << sideA << std::endl;
                std::cout << "   + sideB: " << sideB << std::endl;
                std::cout << "   + sideC: " << sideC << std::endl;
            }

        ~Triangle() {}

        // Heron's  formula
        float area() const {
            float total;
            float area;

            total = (this->_sideA + this->_sideB + this->_sideC) / 2;
            area = total * (total - this->_sideA) * (total - this->_sideB) * (total - this->_sideC);
            area = std::sqrt(area);

            return area;
        }

        float perimeter() const {
            return this->_sideA + this->_sideB + this->_sideC;
        }

    private:

        float _sideA;
        float _sideB;
        float _sideC;

        Triangle() {};

};