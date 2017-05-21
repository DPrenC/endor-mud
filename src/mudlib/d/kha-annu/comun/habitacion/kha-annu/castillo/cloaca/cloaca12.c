#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("Hay algo más de luz aquí. El corredor continúa de este a oeste.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("suelo","El suelo está cubierto de un extraño líquido de color marrón.\n");
    AddExit("oeste",CLOACAS+"cloaca13");
    //AddExit("este",CLOACAS+"cloaca11");
    AddItem(MONS+"rata",REFRESH_DESTRUCT,1);
    AddItem(MONS+"slug",REFRESH_DESTRUCT,1);
}
