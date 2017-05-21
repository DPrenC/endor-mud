#include "./path.h"

inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("la calle Kilok");
    SetIntLong("Te encuentras en la calle Kilok, bordeando una posada. La calle continúa al "
        "norte después de doblar la esquina.\n");
    SetIntBright(80);
    SetIndoors(1);
    AddExit("norte",CIUDAD+"grimly12");
    AddExit("sur",CIUDAD+"baldur12");
    AddExit("oeste",POSADAS+"dazul/posada");
  SetLocate("ciudad de Kha-Annu");
}
