/* Archivo:         labranza07.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte y eleste hay una empalizada de "
        "madera que te separa del camino de la granja. Al oeste tienes la "
        "pared de una cabaña de la aldea.\n");
    AddDetail(({"cabaña","pared"}),"Ves la pared de maderos mal encajados, "
        "perteneciente a la parte trasera de una de las cabañas de la aldea "
        "que te inpide ir en esa dirección.\n");
    AddDetail(({"empalizada","cerca"}),"Corta el paso entre los cultivos y "
        "el camino de la granja para que no se cuele ningún animal o persona.\n");
    AddExit("sur", SHERALD("campo/labranza08"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
