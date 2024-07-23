#pragma once

#include <iostream>

#include "Tool.hpp"

class Worker;

struct Hammer : public Tool {

    private:

        int _numberOfUses;
        Worker *_owner;

    public:

        Hammer();
        ~Hammer();

        void use();
        void own(Worker *worker);
        int get_number_of_uses() const;

};

std::ostream& operator << (std::ostream& os, const Hammer& hammer);