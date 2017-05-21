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
    SetIntShort("el borde del r�o");
    SetIntLong("Hay un peque�o claro en la parte Oeste que te permite adentrarte en el bosque "
        "Wald. Por el contrario si contin�as por el Sur llegar�s a lo que parece ser la "
        "desembocadura del r�o Cashigan en el mar.\n");
#include INC"d_cashigan.inc"
    AddRoomCmd("beber",SF(beber));
    AddExit("norte",BWALD("borde_rio11"));
    AddExit("sur",BWALD("borde_rio13"));
    AddExit("suroeste",BWALD("bosque17"));
    AddPnj();
    SetLocate("bosque Wald");
}
