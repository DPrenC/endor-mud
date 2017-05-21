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
    AddExit("norte",BOSCURO("bosque10"));
    AddExit("oeste",ACANTILADO("acantilado3"));
    AddPnj();
    AddFlor();
    SetLocate("bosque oscuro de Goldhai");
}
