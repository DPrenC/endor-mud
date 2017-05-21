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
"Aqui es donde descansan todos aquellos que est�n intentando convertirse en "
"wizards. Hay unas veinte camas, aunque te da la impresi�n que muchas de ellas "
"est�n actualmente desocupadas.\n");

    SetIntBright(20);

    AddDetail (({"cama","camas"}),"Cuentas exactamente 21 camas, pero no crees "
    "que todas est�n ocupadas.\n");

    AddExit("sur",   TORRE("sotano/center"));
}
