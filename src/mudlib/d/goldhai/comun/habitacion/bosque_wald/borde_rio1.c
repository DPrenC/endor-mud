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
    SetIntLong("Te encuentras en la parte oeste del r�o Cashigan. Un poco m�s al Norte "
        "consigues vislumbrar lo que parece ser la silueta de un puente, el cu�l te permitir� "
        "cruzar al otro lado. El r�o te impide ir al nordeste pero puedes continuar su "
        "recorrido si vas hacia el Este o el Sur. En el Oeste ves un camino de piedras que te "
        "conduce a la entrada de una granja.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("oeste",BWALD("camino_granja5"));
    AddExit("sur",BWALD("borde_rio2"));
    AddPnj();
    SetLocate("bosque Wald");
}

