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
    SetIntLong("Te encuentras en uno de los recodos del r�o Cashigan, el cu�l transcurre por "
        "el Este y el Sur, mientras que en el oeste los �rboles del bosque Wald te impiden el "
        "paso. Puedes continuar bordeando el recodo en direcci�n Suroeste o bien subir por la "
        "orilla hacia el Norte.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio7"));
    AddExit("suroeste",BWALD("borde_rio9"));
    AddPnj();
    SetLocate("bosque Wald");
}
