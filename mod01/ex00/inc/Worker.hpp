#pragma once

#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel.hpp"

class Worker {

    private:
        Position _coordonnee;
        Statistic _stat;
        Shovel* _shovel;

    public:

        Worker(int x, int y, int z, int exp, int level);
        ~Worker();

        const Position& get_position() const;
        const Statistic& get_stat() const;
        bool equip_shovel(Shovel *shovel);
        void unequip_shovel();

};

std::ostream& operator << (std::ostream& os, const Worker& worker);