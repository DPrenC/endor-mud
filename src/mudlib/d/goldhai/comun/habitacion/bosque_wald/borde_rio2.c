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
    SetIntShort("la orilla oeste del r�o Cashigan");
    SetIntLong("El r�o Cashigan te impide ir en direcci�n este y la frondosa vegetaci�n del "
        "bosque te lo impide en direcci�n oeste por lo que tus �nicas opciones son seguir "
        "recorriendo la orilla oeste del r�o hacia el Norte o hacia el Sur.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio1"));
    AddExit("sur",BWALD("borde_rio3"));
    AddPnj();
    SetLocate("bosque Wald");
}
