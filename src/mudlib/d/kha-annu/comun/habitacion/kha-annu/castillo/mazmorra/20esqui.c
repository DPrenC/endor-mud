#include "path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la esquina del pasillo");
    SetIntLong("Aquí el pasillo gira, puedes ir hacia el oeste o hacia el norte. Puertas "
        "ves por los pasillos, todas iguales, todas equidistantes, parece que la mazmorra está "
        "hecha a conciencia.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada.\n");
    SetIntSmell("No huele a nada, excepto un hilillo de humedad.\n");
    AddExit("norte",("19pas"));
    AddExit("oeste",("21pas"));
    SetLocate("las mazmorras");
}
