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
    SetIntShort("el bosque Wald, junto a una caba�a");
    SetIntLong(QueryIntLong()+ " En esta partte del frondoso bosque se levanta una "
    "peque�a y ruinosa caba�a destartalada.\n");
    AddExit("entrar",BWALD("tienda_gnomo"));
    AddExit("este",BWALD("bosque23"));
    AddDetail(({"casa", "caba�a", "caba�a de madera"}),
    "Una peque�a caba�a de madera construida apoyada en el gran tronco de un �rbol, "
    "parece vieja, pero se mantiene firme.\n");
    AddDoor("entrar", "la puerta de la caba�a",
    "Es una destartalada puerta de madera para entrar a la caba�a.\n",
    ({"puerta", "puerta de la caba�a", "puerta destartalada", "puerta de madera"}));

    AddPnj();
    SetLocate("bosque Wald");
}
