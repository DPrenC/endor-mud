// Coded by Kayra.
/* Fixed by Fran@Simauria Sept 2000
*/
#include "path.h"
inherit KHA_ROOM;
#include "path.h"
#include "darts.h"

create()
{
    ::create();
    SetIntShort("las cloacas");
    SetIntBright(30);
    SetIntLong("El corredor es mas espacioso aquí. No ves nada especial.\n");
    AddDetail(({"roturas","rotura","pared","paredes","liquido","líquido","grieta","grietas"}),
        "Ves unos pequeños agujeros en la pared, que casi está a punto de desmoronarse.\n");
    AddDetail("suelo","El suelo está lleno de restos de comida podrida. Parece que nadie ha "
        "pasado por aquí desde hace tiempo.\n");
    AddExit("norte",CLOACAS+"cloaca25");
    AddExit("sur",CLOACAS+"cloaca23");
}
