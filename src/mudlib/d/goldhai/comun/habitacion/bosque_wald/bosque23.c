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
    AddExit("sudeste",BWALD("bosque21"));
    AddExit("este",BWALD("bosque22"));
    AddExit("oeste",BWALD("bosque24"));
    AddPnj();
    SetLocate("bosque Wald");
}
