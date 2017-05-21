#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("Estás en las cloacas. En este lugar ves que el corredor continúa de este a "
        "oeste, y que un cruce conduce hacia el sur.\n");
    SetIntBright(30);
    AddDetail("suelo","El suelo está cubierto de un fétido líquido de color parduzco.\n");
    AddExit("oeste",CLOACAS+"cloaca15");
    AddExit("sur",CLOACAS+"cloaca38");
    AddExit("este",CLOACAS+"cloaca13");
}

