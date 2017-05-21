// Coded by Kayra.
/* Fixed by Fran@Simauria Sept 2000
*/
#include "path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntBright(30);
    SetIntLong("El pasillo es menos estrecho aqu�. No ves nada.\n");
    AddDetail(({"roturas","rotura","pared","paredes","liquido","grieta","grietas","l�quido"}),
        "Ves unos peque�os agujeros en la pared, que casi est� a punto de desmoronarse.\n");
    AddDetail("suelo","El suelo est� lleno de restos de comida podrida. Parece que nadie ha "
        "pasado por aqu� desde hace tiempo.\n");
    AddExit("norte",CLOACAS+"cloaca23");
    AddExit("oeste",CLOACAS+"cloaca21");
}
