#include "path.h"

inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("Te encuentras en las cloacas del castillo. La humedad invade el lugar y las "
        "paredes est�n recubiertas de un moho de color marr�n. El olor aqu� es nauseabundo, "
        "casi espeso.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDetail(({"moho","pared","paredes"}),"Las paredes est�n recubiertas de un moho baboso de "
        "color marr�n.\n");
    AddDetail(({"suelo","restos","comida"}),"Esparcidos por el suelo ves restos de comida y "
        "heces.\n");
    AddExit("norte",CLOACAS+"cloaca5");
    AddExit("sur",CLOACAS+"cloaca3");
    AddItem(MONS+"rata",REFRESH_DESTRUCT,1);
}
