/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 27-08-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    SetIntShort("el bosque Wald, junto a una cabaña");
    SetIntLong(QueryIntLong()+ " En esta partte del frondoso bosque se levanta una "
    "pequeña y ruinosa cabaña destartalada.\n");
    AddExit("entrar",BWALD("tienda_gnomo"));
    AddExit("este",BWALD("bosque23"));
    AddDetail(({"casa", "cabaña", "cabaña de madera"}),
    "Una pequeña cabaña de madera construida apoyada en el gran tronco de un árbol, "
    "parece vieja, pero se mantiene firme.\n");
    AddDoor("entrar", "la puerta de la cabaña",
    "Es una destartalada puerta de madera para entrar a la cabaña.\n",
    ({"puerta", "puerta de la cabaña", "puerta destartalada", "puerta de madera"}));

    AddPnj();
    SetLocate("bosque Wald");
}
