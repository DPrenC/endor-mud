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
    AddExit("este",BWALD("borde_rio3"));
    AddExit("norte",BWALD("bosque16"));
    AddExit("oeste",BWALD("bosque14"));
    AddPnj();
    SetLocate("bosque Wald");
}
