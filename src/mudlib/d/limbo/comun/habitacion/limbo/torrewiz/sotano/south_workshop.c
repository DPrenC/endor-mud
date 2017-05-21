/**
 * /torrewiz/sotano/south_workshop.c
 */

#include "path.h"
inherit ROOM;

create() {
    ::create();

    SetIntShort("un lugar de trabajo para aprendices");
    SetIntLong(
"Estas en una enorme habitación. Sus paredes reforzadas hacen notar que "
"los mas complicados experimentos que los aprendices recrean en este lugar "
"solo son conocidos a traves de la habilidad de los verdaderos wizards. "
"Una puerta al norte conduce a la habitación principal.\n");

    SetIntBright(50);

    AddExit("norte", TORRE("sotano/center"));
}