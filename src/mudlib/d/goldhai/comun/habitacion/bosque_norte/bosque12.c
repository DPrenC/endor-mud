/*=============================================================*
 |            << GOLDHAI.Bosque [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 08-02-99               |
 |               Ultima Modificacion... 08-02-99               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    AddExit("norte",BNORTE("bosque9"));
    AddExit("sur",BNORTE("bosque13"));
    AddPnj();
    AddFlor();
    SetLocate("bosque norte de Goldhai");
}
