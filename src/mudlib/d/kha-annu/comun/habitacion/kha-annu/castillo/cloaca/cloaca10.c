#include "path.h"
inherit KHA_ROOM;
#include "sticks.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntLong("No logras ver nada, pero jurar�as que el corredor est� ensanch�ndose. Al "
        "caminar produces un chapoteo.\n");
    SetIndoors(1);
    SetIntBright(30);
    //AddExit("norte",CLOACAS+"cloaca11");
    AddExit("sur",CLOACAS+"cloaca9");
}

