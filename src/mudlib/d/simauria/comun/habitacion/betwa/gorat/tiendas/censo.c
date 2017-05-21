/** Censo de Gorat
 * /d/simauria/comun/habitacion/betwa/gorat/tiendas/censo
 */

#include "./path.h"
inherit SCHEDULER_ROOM;
inherit "/room/censo";

create() {
    ::create();

    SetCity("Gorat");
    SetLocate("Gorat");
    SetIntShort("el censo de Gorat");
    SetIntLong("Te encuentras en el censo del pueblo pesquero de Gorat, donde te puedes hacer "
               "pueblerino de este pequeño pueblo pesquero .\n  De esta oficina "
               "se encarga el bueno de Dunkan, si quieres informacion pregúntale.\n");

    SetIntBright(30);

    AddExit("abajo", "./ayuntamiento");
    AddItem(GORPNJ("dunkan"),REFRESH_DESTRUCT);
    SetMainRoom("./ayuntamiento");
    SetNotifyExits(({}));
    SetLastDest("../calles/callep6");
}
