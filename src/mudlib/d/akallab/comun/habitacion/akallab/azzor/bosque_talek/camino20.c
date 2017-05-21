/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino10.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <moving.h>
inherit BOSQUE_TALEK("camino");

int ir_ne()
{
    if (TP->QueryIsPlayer()) return TP->move(AZ_CAMINO("camino16"),M_GO);
    return 1;
}

create()
{
    ::create();
   SetIntLong("Te encuentras al inicio del bosque de Talek, un inmenso y "
        "denso bosque que se halla en el suroeste del valle de Azzor. Hacia "
        "el sur, este camino de tierra se adentra en este bosque, y hacia el "
        "nordeste lo deja atrás.\n");
    AddExit("oeste",BOSQUE_TALEK("bosque72"));
    AddExit("este",BOSQUE_TALEK("bosque73"));
    AddExit("sur",BOSQUE_TALEK("camino19"));
    AddExit("nordeste",SF(ir_ne));
}
