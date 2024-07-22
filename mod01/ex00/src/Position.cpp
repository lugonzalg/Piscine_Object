#include <iostream>

#include "Position.hpp"

Position::Position(int x, int y, int z) : _x(x), _y(y), _z(z) {
    std::cout << "Positon constructor with coords. x: " << x
        << ", y: " << y << ", z: " << z << std::endl;
}

Position::~Position() {
    std::cout << "Postion destructor\n";
}

int Position::get_x() const {
    return this->_x;
}

int Position::get_y() const {
    return this->_y;
}

int Position::get_z() const {
    return this->_z;
}