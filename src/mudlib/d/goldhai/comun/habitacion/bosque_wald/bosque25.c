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
    AddExit("oeste",BWALD("bosque22"));
    AddExit("este",BWALD("bosque26"));
    AddExit("suroeste",BWALD("bosque21"));
    AddPnj();
    SetLocate("bosque Wald");
}
