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
    AddExit("este",BWALD("borde_rio12"));
    AddExit("oeste",BWALD("bosque19"));
    AddExit("sur",BWALD("bosque17"));
    AddExit("sudeste",BWALD("borde_rio13"));
    AddPnj();
    SetLocate("bosque Wald");
}
