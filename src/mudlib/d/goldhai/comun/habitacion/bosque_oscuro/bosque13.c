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
    AddExit("norte",BOSCURO("bosque14"));
    AddExit("oeste",BOSCURO("frente_faro1"));
    AddExit("sur",BOSCURO("bosque10"));
    AddPnj();
    AddFlor();
    SetLocate("bosque oscuro de Goldhai");
}
