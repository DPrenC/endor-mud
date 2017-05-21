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
    SetIntShort("una bifurcaci�n");
    SetIntLong("Has llegado a una de las tantas bifurcaciones que tiene este bosque. All� a lo "
        "lejos en la parte Norte ves lo que parecen ser unas murallas, as� que si quieres "
        "encontrar algo de civilizaci�n ser�a recomendable que continuases por este camino en "
        "direcci�n Norte. Por los otros caminos te adentrar�s a�n m�s en el bosque oscuro.\n");
     AddExit("norte",BOSCURO("bosque2"));
    AddExit("oeste",BOSCURO("bosque12"));
    AddExit("sur",BOSCURO("bosque4"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
