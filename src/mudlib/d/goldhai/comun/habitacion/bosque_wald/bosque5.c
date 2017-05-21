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
    AddExit("este",BWALD("bosque6"));
    AddExit("suroeste",BWALD("bosque3"));
    AddExit("sur",BWALD("bosque4"));
    AddExit("sudeste",BWALD("bosque7"));
    AddPnj();
    SetLocate("bosque Wald");
}
