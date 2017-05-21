/* Archivo:         labranza05.c
Autor:           Yalin y Lug
Descripción:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este hay una empalizada de madera "
        "que te separa del camino de la granja. Hacia el sur ves la pared "
        "de uno de los establos. En las demás direcciones continúan los "
        "campos de cultivo.\n");
    AddDetail(({"pared"}), "Es la pared lateral de uno de los establos de la "
        "granja. Está construida con grandes y sólidos maderos, pero no "
        "tiene ninguna otra peculiaridad que te parezca interesante.\n");
    AddDetail(({"empalizada","cerca"}),"Corta el paso entre los cultivos y "
        "el camino de la granja para que no se cuele ningún animal o persona.\n");
    AddExit("norte", SHERALD("campo/labranza06"));
    AddExit("oeste", SHERALD("campo/labranza09"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
