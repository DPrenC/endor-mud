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
    AddExit("oeste",BWALD("bosque2"));
    AddExit("este",BWALD("bosque4"));
    AddExit("nordeste",BWALD("bosque5"));
    AddPnj();
    SetLocate("bosque Wald");
}
