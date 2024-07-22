#pragma once

#include "Position.hpp"
#include "Statistic.hpp"

class Worker {

    private:
        Position& _coordonnee;
        Statistic& _stat;

    public:

        Worker(int x, int y, int z, int exp, int level);
        ~Worker();

};

std::ostream& operator << (std::ostream& os, const Worker& worker);