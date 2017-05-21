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
    SetIntShort("la desembocadura del r�o");
    SetIntLong("Te encuentras en la orilla oeste de la desembocadura del r�o Cashigan. Desde "
        "este lugar se puede ver perfectamente toda la costa sur de la isla y el mar que azota "
        "�sta con fuerza y bravura. Puedes seguir por la costa si vas en direcci�n Oeste o "
        "bien adentrarte en el bosque si vas al Noroeste. El r�o se adentra en Goldhai hacia "
        "el Norte.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio12"));
    AddExit("noroeste",BWALD("bosque18"));
    AddExit("oeste",BWALD("bosque17"));
    AddPnj();
    SetLocate("bosque Wald");
}
