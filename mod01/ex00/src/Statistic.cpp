
#include "Statistic.hpp"

Statistic::Statistic(int exp, int level) : _exp(exp), _level(level) {

    std::cout << "Statistic constructor with values. exp: "
        << exp << ", level: " << _level << std::endl;

}

Statistic::~Statistic() {
    std::cout << "Statistic destructor\n";
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
    std::cout << 
}

int Statistic::get_exp() const {
    return this->_exp;
}

int Statistic::get_level() const {
    return this->_level;
}