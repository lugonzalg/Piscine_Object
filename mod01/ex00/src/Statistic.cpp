
#include "Statistic.hpp"

Statistic::Statistic(int exp, int level) : _exp(exp), _level(level) {

    std::cout << "Statistic constructor with values. exp: "
        << exp << ", level: " << _level << std::endl;

}

Statistic::~Statistic() {
    std::cout << "Statistic destructor\n";
}

int Statistic::get_exp() const {
    return this->_exp;
}

int Statistic::get_level() const {
    return this->_level;
}

//OPERATORS

std::ostream& operator << (std::ostream& os, const Statistic& stat) {

    os << "exp: " << stat.get_exp() << "\nlevel: " << stat.get_level() << std::endl;

    return os;
}