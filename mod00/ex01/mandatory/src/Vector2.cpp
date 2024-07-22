#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

float Vector2::get_x() const {
    return this->_x;
}
float Vector2::get_y() const {
    return this->_y;
}