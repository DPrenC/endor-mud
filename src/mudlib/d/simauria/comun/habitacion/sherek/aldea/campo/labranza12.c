/* Archivo:         labranza12.c
   Autor:           Yalin y Lug
   Descripción:     Cultivos en la granja de la aldea de Sloch
   Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte se encuentra la pared trasera de una "
        "cabaña, mientras al oeste un muro te cierra el paso.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, para impedir el paso de los perros y los "
        "niños que juegan en la pradera vecina.\n");
    AddDetail(({"cabaña","pared"}),"Ves la pared de maderos mal encajados, "
        "perteneciente a la parte trasera de una de las cabañas de la aldea "
        "que te inpide ir en esa dirección.\n");
    AddExit("sur", SHERALD("campo/labranza13"));
    AddExit("este", SHERALD("campo/labranza08"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
