/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino10.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>
inherit BOSQUE_TALEK("camino");

int ir_e()
{
    if (TP->QueryIsPlayer()) return TP->move(AZ_CAMINO("camino00"),M_GO);
    return 1;
}

create()
{
    ::create();
   SetIntLong("Te encuentras al inicio del bosque de Talek, un inmenso y "
        "denso bosque que se halla en el suroeste del valle de Azzor. Hacia "
        "el oeste, el Camino del Este se adentra en este bosque, y hacia el "
        "este se aleja de él.\n");
    AddExit("norte",BOSQUE_TALEK("bosque33"));
    AddExit("oeste",BOSQUE_TALEK("camino09"));
    AddExit("este",SF(ir_e));
}
