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
    AddExit("norte",BNORTE("bosque1"));
    AddExit("sur",BNORTE("bosque8"));
    AddPnj();
    AddFlor();
    SetLocate("bosque norte de Goldhai");
}
