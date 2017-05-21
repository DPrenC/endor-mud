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
    SetIntShort("la orilla oeste del r�o Cashigan");
    SetIntLong("El r�o Cashigan resulta pr�cticamente imposible de cruzar desde esta parte en "
        "la que te encuentras. Sin embargo, un poco m�s al sur, parece que el r�o se estrecha "
        "considerablemente. Puedes continuar bordeando el r�o si vas al Norte o al Sur. El "
        "bosque Wald te impide ir en direcci�n oeste.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio3"));
    AddExit("sur",BWALD("borde_rio5"));
    AddPnj();
    SetLocate("bosque Wald");
}
