/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino01.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Te encuentras al inicio del bosque de Talek, un inmenso y "
        "denso bosque que se halla en el suroeste del valle de Azzor. Hacia "
        "el sudeste, el Camino del Este se adentra en este bosque, y hacia "
        "el noroeste se aleja de él, ascendiendo hacia las montañas.\n");
    AddExit("noroeste",BOSQUE_TALEK("camino00"));
    AddExit("sudeste",BOSQUE_TALEK("camino02"));
    AddExit("este",BOSQUE_TALEK("bosque34"));
    AddExit("sur",BOSQUE_TALEK("bosque30"));
}
