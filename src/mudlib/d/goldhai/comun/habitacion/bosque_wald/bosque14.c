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
    AddExit("este",BWALD("bosque15"));
    AddExit("sur",BWALD("bosque9"));
    AddExit("oeste",BWALD("bosque13"));
    AddExit("suroeste",BWALD("bosque12"));
    AddPnj();
    SetLocate("bosque Wald");
}
