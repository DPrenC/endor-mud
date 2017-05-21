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
    AddExit("norte",BNORTE("bosque16"));
    AddExit("oeste",BNORTE("bosque14"));
    AddPnj();
    SetLocate("bosque norte de Goldhai");
}
