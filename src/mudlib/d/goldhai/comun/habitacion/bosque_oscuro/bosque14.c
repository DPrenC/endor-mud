/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 06-01-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    AddExit("norte",BOSCURO("bosque15"));
    AddExit("sur",BOSCURO("bosque13"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
