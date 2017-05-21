#include "path.h"
inherit KHA_ROOM;
#include "stink.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("El corredor parece ensancharse un poco. Al moverte, produces un sonido de "
        "chapoteo al pisar el líquido inmundo que inunda el suelo de este lugar.\n");
    SetIndoors(1);
    SetIntBright(30);
    AddDetail(({"suelo","agua","liquido","líquido"}),"Ves restos de comida flotando en el "
        "líquido que pisas.\n");
    AddItem("/d/kha-annu/comun/objeto/otro/llavecel",REFRESH_DESTRUCT,1);
    AddExit("norte",CLOACAS+"cloaca9");
    AddExit("oeste",CLOACAS+"cloaca7");
}
