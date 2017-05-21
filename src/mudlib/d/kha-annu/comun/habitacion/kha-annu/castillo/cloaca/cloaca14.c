#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("Est�s en las cloacas. En este lugar ves que el corredor contin�a de este a "
        "oeste, y que un cruce conduce hacia el sur.\n");
    SetIntBright(30);
    AddDetail("suelo","El suelo est� cubierto de un f�tido l�quido de color parduzco.\n");
    AddExit("oeste",CLOACAS+"cloaca15");
    AddExit("sur",CLOACAS+"cloaca38");
    AddExit("este",CLOACAS+"cloaca13");
}

