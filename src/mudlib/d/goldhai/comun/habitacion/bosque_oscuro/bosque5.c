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
    SetIntLong("Vas caminando a trav�s de los �rboles y los matorrales del bosque oscuro de "
        "Goldhai. Al Sur te parece ver un peque�o claro.\n");
    AddDetail("claro","Parece ser una zona con una vegetaci�n no tan espesa.\n");
    AddExit("norte",BOSCURO("bosque4"));
    AddExit("sur",BOSCURO("bosque6"));
    AddPnj();
    AddFlor();
    SetLocate("bosque oscuro de Goldhai");
}
