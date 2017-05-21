/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 18-11-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    AddExit("este",BOSCURO("bosque6"));
    AddExit("oeste",BOSCURO("bosque8"));
    AddPnj();
    AddFlor();
    SetLocate("bosque oscuro de Goldhai");
}
