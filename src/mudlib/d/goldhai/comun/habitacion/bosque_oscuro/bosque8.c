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
    AddExit("este",BOSCURO("bosque7"));
    AddExit("oeste",BOSCURO("frente_vudu"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
