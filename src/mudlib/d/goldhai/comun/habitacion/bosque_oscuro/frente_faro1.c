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
    AddExit("este",BOSCURO("bosque13"));
    AddExit("oeste",BOSCURO("camino_puerto3"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
