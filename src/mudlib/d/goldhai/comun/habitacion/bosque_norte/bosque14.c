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
    AddExit("este",BNORTE("bosque15"));
    AddExit("sur",BNORTE("alrededor_crowy10"));
    AddPnj();
    SetLocate("bosque norte de Goldhai");
}
