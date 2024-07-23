#pragma once

#include <iostream>
#include <string>

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"

class Workshop;

class Worker {

    private:
        const std::string _name;
        Position _coordonnee;
        Statistic _stat;
        Tool* _tool;

    public:

        Worker(const std::string name, int x, int y, int z, int exp, int level);
        ~Worker();

        const Position& get_position() const;
        const Statistic& get_stat() const;
        const std::string& get_name() const;

        bool equip_tool(Tool *tool);
        void unequip_tool();
        void work();
};

std::ostream& operator << (std::ostream& os, const Worker& worker);