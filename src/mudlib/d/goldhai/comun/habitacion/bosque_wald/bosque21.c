/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 27-08-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
        ::create();
    SetIntShort("el bosque Wald");
    AddExit("norte",BWALD("bosque22"));
    AddExit("sur",BWALD("bosque20"));
    AddExit("nordeste",BWALD("bosque25"));
    AddExit("noroeste",BWALD("bosque23"));
    AddPnj();
    SetLocate("bosque Wald");
}
