#include <iostream>

#include "Position.hpp"

Position::Position(int x, int y, int z) : _x(x), _y(y), _z(z) {
    std::cout << "[POSITON] - constructor called\n";
    std::cout << *this << std::endl;
}

Position::~Position() {
    std::cout << "[POSITION] - destructor called\n";
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

std::ostream& operator << (std::ostream& os, const Position& pos) {

    os << "[POSITION] - x: " << pos.get_x() << ", y: " << pos.get_y() << ", z: " << pos.get_z();
    return os;
}