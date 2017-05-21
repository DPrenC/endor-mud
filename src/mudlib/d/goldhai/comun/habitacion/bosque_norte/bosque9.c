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
    AddExit("este",BNORTE("bosque8"));
    AddExit("oeste",BNORTE("bosque10"));
    AddExit("sur",BNORTE("bosque12"));
    AddPnj();
    SetLocate("bosque norte de Goldhai");
}
