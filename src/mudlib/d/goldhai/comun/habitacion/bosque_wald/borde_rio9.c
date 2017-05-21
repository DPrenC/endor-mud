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
    SetIntLong("Una pequeña senda se adentra en el bosque Wald en el Oeste mientras que en la "
        "   parte este el río Cashigan solo te permite proseguir en dirección Sur y Nordeste.\n");
    AddDetail(({"paso","camino","senda"}),"Una pequeña senda que se adentra en el bosque.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("nordeste",BWALD("borde_rio8"));
    AddExit("sur",BWALD("borde_rio10"));
    AddExit("oeste",BWALD("bosque26"));
    AddPnj();
    SetLocate("bosque Wald");
}
