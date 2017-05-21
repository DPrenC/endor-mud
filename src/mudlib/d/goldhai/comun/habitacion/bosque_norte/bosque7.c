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
    AddExit("este",BNORTE("bosque6"));
    AddExit("oeste",BNORTE("bosque8"));
    AddPnj();
    SetLocate("bosque norte de Goldhai");
}
