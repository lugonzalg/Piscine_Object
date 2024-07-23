#include <iostream>

#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

int main() {

    Worker mark(0,0,0,0,0);
    Worker jake(0,0,0,0,0);

    Shovel shovel;
    Hammer hammer;

    mark.equip_tool(NULL);
    jake.equip_tool(NULL);

    mark.equip_tool(&shovel);
    jake.equip_tool(&shovel);
    jake.equip_tool(&hammer);
    mark.equip_tool(&hammer);

    mark.unequip_tool();
    jake.unequip_tool();
    return 0;
}