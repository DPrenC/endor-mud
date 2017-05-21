/* Archivo:         labranza16.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el sureste puedes salir a la calle de "
        "la granja, al oeste hay un muro que rodea el sembrado y en las "
        "demás direcciones continúa la plantación.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, para impedir el paso de los perros y los "
        "niños que juegan en la pradera vecina.\n");
    AddExit("sudeste", SHERALD("granja/granja05"));
    AddExit("norte", SHERALD("campo/labranza15"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
