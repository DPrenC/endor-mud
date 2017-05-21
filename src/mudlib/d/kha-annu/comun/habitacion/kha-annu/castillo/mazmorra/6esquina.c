#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la esquina del pasillo");
    SetIntLong("Aqui el pasillo gira, puedes ir hacia el norte o hacia el este.\nPuertas es lo "
        "único que ves por los dos corredores.\n");
    SetIndoors(1);    
    SetIntBright(10);
    SetIntNoise("Esto está en silencio.\n");
    SetIntSmell("Ya no hueles a nada.\n");
    AddExit("norte",("7pas"));
    AddExit("este",("5pas"));
    SetLocate("las mazmorras");
}
