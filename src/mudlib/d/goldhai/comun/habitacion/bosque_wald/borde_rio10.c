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
    SetIntLong("Estás en un camino que pasa entre la orilla oeste del río Cashigan y el bosque "
        "Wald. Puedes continuar hacia el Norte o hacia el Sur recorriendo el margen del río.\n");
    AddDetail(({"camino"}),"Es un camino corriente de tierra y piedras.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio9"));
    AddExit("sur",BWALD("borde_rio11"));
    AddPnj();
    SetLocate("bosque Wald");
}
