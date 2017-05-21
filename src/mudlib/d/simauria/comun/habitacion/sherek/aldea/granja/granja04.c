/* Archivo        granja04.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Puedes ver aquí hacia el sur un corral, Al "
        "norte tienes una pared de gruesos maderos que pertenece a uno de "
        "los establos. Hacia el este y el oeste continúa la calle.\n");
    SetIntNoise("Escuchas a los animales a tu alrededor y el sonido del río.\n");
    SetIntSmell("Huele a humedad y a animales en cautividad.\n");
    AddDetail(({"pared", "maderos"}), "Se trata de la pared de uno de los establos de la granja. "
    "Parece muy robusta.\n");
    AddDetail(({"corral"}), "Es una empalizada donde se encierran las aves de la granja.\n");
    AddExit("oeste", SHERALD("granja/granja05"));
    AddExit("este", SHERALD("granja/granja03"));
    AddExit("sur", SHERALD("granja/corral"));
}
