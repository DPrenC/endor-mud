#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("Hay algo m�s de luz aqu�. El corredor contin�a de este a oeste.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("suelo","El suelo est� cubierto de un extra�o l�quido de color marr�n.\n");
    AddExit("oeste",CLOACAS+"cloaca13");
    //AddExit("este",CLOACAS+"cloaca11");
    AddItem(MONS+"rata",REFRESH_DESTRUCT,1);
    AddItem(MONS+"slug",REFRESH_DESTRUCT,1);
}
