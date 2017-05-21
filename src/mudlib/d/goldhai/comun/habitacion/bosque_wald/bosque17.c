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
    AddExit("norte",BWALD("bosque18"));
    AddExit("este",BWALD("borde_rio13"));
    AddExit("nordeste",BWALD("borde_rio12"));
    AddPnj();
    SetLocate("bosque Wald");
}
