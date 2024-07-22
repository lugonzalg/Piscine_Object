#pragma once

#include <iostream>

class Statistic {

    private:

        int _exp;
        int _level;

    public:

        Statistic(int exp, int level);
        ~Statistic();
        int get_exp() const;
        int get_level() const;

};

std::ostream& operator << (std::ostream& os, const Statistic& stat);