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
    AddExit("oeste",BWALD("bosque4"));
    AddExit("norte",BWALD("bosque6"));
    AddExit("noroeste",BWALD("bosque5"));
    AddPnj();
    SetLocate("bosque Wald");
}
