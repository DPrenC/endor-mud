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
    AddExit("norte",BOSCURO("bosque1"));
    AddExit("sur",BOSCURO("bosque3"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
