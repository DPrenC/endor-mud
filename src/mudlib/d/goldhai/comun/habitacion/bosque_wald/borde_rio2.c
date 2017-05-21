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
    SetIntShort("la orilla oeste del río Cashigan");
    SetIntLong("El río Cashigan te impide ir en dirección este y la frondosa vegetación del "
        "bosque te lo impide en dirección oeste por lo que tus únicas opciones son seguir "
        "recorriendo la orilla oeste del río hacia el Norte o hacia el Sur.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio1"));
    AddExit("sur",BWALD("borde_rio3"));
    AddPnj();
    SetLocate("bosque Wald");
}
