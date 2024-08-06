#include <iostream>

#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

int main() {

    Workshop wksph1;
    Workshop wksph2;

    Worker mark("Mark", 0,0,0,0,0);
    Worker jake("Jake", 0,0,0,0,0);

    wksph1.register_worker(&mark);
    wksph2.register_worker(&mark);
    wksph1.register_worker(&jake);
    wksph2.register_worker(&jake);


    wksph1.release_worker(&jake);
    wksph1.executeWorkDay();
    wksph2.executeWorkDay();

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