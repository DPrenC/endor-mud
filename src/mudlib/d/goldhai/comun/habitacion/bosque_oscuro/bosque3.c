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
    SetIntShort("una bifurcación");
    SetIntLong("Has llegado a una de las tantas bifurcaciones que tiene este bosque. Allá a lo "
        "lejos en la parte Norte ves lo que parecen ser unas murallas, así que si quieres "
        "encontrar algo de civilización sería recomendable que continuases por este camino en "
        "dirección Norte. Por los otros caminos te adentrarás aún más en el bosque oscuro.\n");
     AddExit("norte",BOSCURO("bosque2"));
    AddExit("oeste",BOSCURO("bosque12"));
    AddExit("sur",BOSCURO("bosque4"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
