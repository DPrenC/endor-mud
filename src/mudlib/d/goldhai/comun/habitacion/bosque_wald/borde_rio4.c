/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 11-05-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;
#include INC"c_beber.inc"

create()
{
    ::create();
    SetIntShort("la orilla oeste del río Cashigan");
    SetIntLong("El río Cashigan resulta prácticamente imposible de cruzar desde esta parte en "
        "la que te encuentras. Sin embargo, un poco más al sur, parece que el río se estrecha "
        "considerablemente. Puedes continuar bordeando el río si vas al Norte o al Sur. El "
        "bosque Wald te impide ir en dirección oeste.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio3"));
    AddExit("sur",BWALD("borde_rio5"));
    AddPnj();
    SetLocate("bosque Wald");
}
