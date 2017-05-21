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
    AddExit("este",BNORTE("bosque4"));
    AddExit("oeste",BNORTE("bosque7"));
    AddPnj();
    AddFlor();
    SetLocate("bosque norte de Goldhai");
}
