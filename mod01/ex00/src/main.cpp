#include <iostream>

#include "Worker.hpp"

int main() {

    Worker mark(0,0,0,0,0);
    Worker jake(0,0,0,0,0);

    Shovel shovel;

    mark.equip_shovel(NULL);
    jake.equip_shovel(NULL);

    mark.equip_shovel(&shovel);
    jake.equip_shovel(&shovel);

    mark.unequip_shovel();
    jake.unequip_shovel();
    return 0;
}