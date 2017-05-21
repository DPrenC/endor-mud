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
    SetIntLong("Estás situado en el margen oeste del río Cashigan. El bosque te impide "
        "progresar en dirección oeste pero puedes continuar por la orilla del río si vas al "
        "Norte o al Sur.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio6"));
    AddExit("sur",BWALD("borde_rio8"));
    AddPnj();
    SetLocate("bosque Wald");
}
