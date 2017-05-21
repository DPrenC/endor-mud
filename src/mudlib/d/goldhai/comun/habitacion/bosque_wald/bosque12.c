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
    AddExit("oeste",BWALD("bosque11"));
    AddExit("norte",BWALD("bosque13"));
    AddExit("nordeste",BWALD("bosque14"));
    AddPnj();
    SetLocate("bosque Wald");
}
