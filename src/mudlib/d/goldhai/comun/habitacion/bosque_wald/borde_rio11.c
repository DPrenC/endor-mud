/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 11-05-99            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;
#include INC"c_beber.inc"

create()
{
    ::create();
    SetIntShort("el borde del río");
    SetIntLong("Vas caminando por el margen oeste del río Cashigan. No tienes más opción que "
        "seguir recorriendo el río hacia el Norte o hacia el Sur.\n");
#include INC"d_cashigan.inc"
     AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio10"));
    AddExit("sur",BWALD("borde_rio12"));
    AddPnj();
    SetLocate("bosque Wald");
}
