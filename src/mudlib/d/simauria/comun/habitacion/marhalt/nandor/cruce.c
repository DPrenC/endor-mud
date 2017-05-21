/*          cruce.c : Aldea de Nandor
            Creado por : Blackrider
            Fecha : 3-6-97
            Ultima modificacion : 30-10-97
*/
#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("un cruce de caminos");
    SetIntLong("Estás en un cruce de caminos de la aldea de Nandor. Al norte puedes ver la "
        "aldea, puedes oír el mugido de las vacas hacia el oeste, al este ves un gran bosque y "
        "hacia el sur puedes ver un largo camino que bordea las montañas. Hay un poste "
        "en medio del camino.\n");
    SetIndoors(0);
    AddItem(PNJ("marhalt/aranya"),REFRESH_DESTRUCT,1);
    AddDetail("poste","Nandor, capital de Marhalt.\n");
    AddExit("norte","./calle7");
    AddExit("este",CNSH("camino00"));
    AddExit("oeste","./sendero9");
    AddExit("sur",CNS("cam01"));
}
