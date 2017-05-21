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
    AddExit("norte",BNORTE("bosque2"));
    AddExit("este",BNORTE("bosque7"));
    AddExit("oeste",BNORTE("bosque9"));
    AddPnj();
    SetLocate("bosque norte de Goldhai");
}
