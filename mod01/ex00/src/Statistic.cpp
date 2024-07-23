
#include "Statistic.hpp"

Statistic::Statistic(int exp, int level) : _exp(exp), _level(level) {

    std::cout << "[STATISTIC] - constructor called\n";
    std::cout << *this << std::endl;

}

Statistic::~Statistic() {
    std::cout << "[STATISTIC] - destructor\n";
}

int Statistic::get_exp() const {
    return this->_exp;
}

int Statistic::get_level() const {
    return this->_level;
}

//OPERATORS

std::ostream& operator << (std::ostream& os, const Statistic& stat) {

    os << "[STATISTIC] - exp: " << stat.get_exp() << ", level: " << stat.get_level();
    return os;
}