#pragma once

#include <iostream>

#include "Tool.hpp"

class Worker;

struct Shovel : public Tool {

    private:

        int _numberOfUses;
        Worker *_owner;

    public:

        Shovel();
        ~Shovel();

        void use();
        void own(Worker *worker);
        int get_number_of_uses() const;

};

std::ostream& operator << (std::ostream& os, const Shovel& shovel);