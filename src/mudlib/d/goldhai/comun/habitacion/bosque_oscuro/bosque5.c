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
    SetIntLong("Vas caminando a través de los árboles y los matorrales del bosque oscuro de "
        "Goldhai. Al Sur te parece ver un pequeño claro.\n");
    AddDetail("claro","Parece ser una zona con una vegetación no tan espesa.\n");
    AddExit("norte",BOSCURO("bosque4"));
    AddExit("sur",BOSCURO("bosque6"));
    AddPnj();
    AddFlor();
    SetLocate("bosque oscuro de Goldhai");
}
