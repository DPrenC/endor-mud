#include "path.h"
inherit KHA_ROOM;

create(){
    ::create();
    SetIntShort("una esquina del pasillo");
    SetIntLong("Aqu� el pasillo gira, puedes ir hacia el oeste o hacia el sur.\nPuertas y "
        "antorchas es lo �nico que ves por los dos corredores.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada.\n");
    SetIntSmell("No huele a nada.\n");
    AddExit("sur",("17pas"));
    AddExit("oeste",("15pas"));
    SetLocate("las mazmorras");
}
