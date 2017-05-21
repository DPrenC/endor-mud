/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 12-09-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;
#include INC"c_beber.inc"

create()
{
    ::create();
    SetIntShort("la orilla oeste del río Cashigan");
    SetIntLong("Estás justo en la parte oeste del río Cashigan y puedes seguir por la orilla "
        "del río si vas en dirección Norte o Sur. Si vas hacia el Oeste te adentrarás un poco "
        "más en el bosque Wald.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio2"));
    AddExit("sur",BWALD("borde_rio4"));
    AddExit("oeste",BWALD("bosque15"));
    AddPnj();
    SetLocate("bosque Wald");
}
