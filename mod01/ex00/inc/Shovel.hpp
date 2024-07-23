#pragma once

#include <iostream>

class Worker;

struct Shovel {

    private:

        int _numberOfUses;
        Worker *_owner;

    public:

        Shovel();
        ~Shovel();

        void own(Worker *);
        int get_number_of_uses() const;

};

std::ostream& operator << (std::ostream& os, const Shovel& shovel);