#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("Sigues en las cloacas y te resulta algo difícil moverte. El ambiente sigue "
        "cargado con un intenso y desagradable olor.\n");
    SetIntBright(30);
    SetIndoors(1);
    SetIntSmell("Percibes un desagradable olor.\n");
    AddExit("norte",CLOACAS+"cloaca6");
/*
    AddExit("oeste",CLOACAS+"cloaca33");
*/
    AddExit("sur",CLOACAS+"cloaca4");
    AddItem(MONS+"rata",REFRESH_DESTRUCT,1);
}
