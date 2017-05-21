#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("una esquina del pasillo");
    SetIntLong("Aquí el pasillo gira, puedes ir hacia el este o hacia el sur.\nPuertas es lo "
        "único que ves por los dos corredores, rodeadas por muros de piedra.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("Unos quejidos parecen venir del sur.\n");
    SetIntSmell("Aquí hay humedad.\n");
    AddExit("sur",("9pas"));
    AddExit("este",("11pas"));
    SetLocate("las mazmorras");
}

