#pragma once

#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Worker {

    private:
        Position _coordonnee;
        Statistic _stat;
        Tool* _tool;

    public:

        Worker(int x, int y, int z, int exp, int level);
        ~Worker();

        const Position& get_position() const;
        const Statistic& get_stat() const;
        bool equip_tool(Tool *tool);
        void unequip_tool();

};

std::ostream& operator << (std::ostream& os, const Worker& worker);