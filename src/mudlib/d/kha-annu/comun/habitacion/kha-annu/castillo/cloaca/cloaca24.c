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
    SetIntLong("El corredor es mas espacioso aqu�. No ves nada especial.\n");
    AddDetail(({"roturas","rotura","pared","paredes","liquido","l�quido","grieta","grietas"}),
        "Ves unos peque�os agujeros en la pared, que casi est� a punto de desmoronarse.\n");
    AddDetail("suelo","El suelo est� lleno de restos de comida podrida. Parece que nadie ha "
        "pasado por aqu� desde hace tiempo.\n");
    AddExit("norte",CLOACAS+"cloaca25");
    AddExit("sur",CLOACAS+"cloaca23");
}
