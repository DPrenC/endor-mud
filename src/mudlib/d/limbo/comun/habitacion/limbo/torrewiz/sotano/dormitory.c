/**
 * /torrewiz/sotano/dormitory.c
 */

#include "path.h"
inherit ROOM;

create() {
    ::create();

    SetIntShort("el dormitorio de aprendices");
    SetIntLong(
"Este es el dormitorio de los aprendices, una silenciosa y oscura habitacion. "
"Aqui es donde descansan todos aquellos que están intentando convertirse en "
"wizards. Hay unas veinte camas, aunque te da la impresión que muchas de ellas "
"están actualmente desocupadas.\n");

    SetIntBright(20);

    AddDetail (({"cama","camas"}),"Cuentas exactamente 21 camas, pero no crees "
    "que todas estén ocupadas.\n");

    AddExit("sur",   TORRE("sotano/center"));
}
