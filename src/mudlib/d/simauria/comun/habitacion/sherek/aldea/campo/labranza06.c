/* Archivo:         labranza06.c
Autor:           Yalin y Lug
Descripci�n:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
::create();
    SetIntLong(QueryIntLong()+"Hacia el norte y eleste hay una empalizada de "
        "madera que te separa del camino de la granja. En las dem�s "
        "direcciones contin�an los campos sembrados.\n");
    AddDetail(({"empalizada","cerca"}),"Corta el paso entre los cultivos y "
        "el camino de la granja para que no se cuele ning�n animal o persona.\n");
    AddExit("sur", SHERALD("campo/labranza05"));
    AddExit("oeste", SHERALD("campo/labranza08"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
