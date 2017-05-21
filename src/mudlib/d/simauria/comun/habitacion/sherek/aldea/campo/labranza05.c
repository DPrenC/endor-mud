/* Archivo:         labranza05.c
Autor:           Yalin y Lug
Descripci�n:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este hay una empalizada de madera "
        "que te separa del camino de la granja. Hacia el sur ves la pared "
        "de uno de los establos. En las dem�s direcciones contin�an los "
        "campos de cultivo.\n");
    AddDetail(({"pared"}), "Es la pared lateral de uno de los establos de la "
        "granja. Est� construida con grandes y s�lidos maderos, pero no "
        "tiene ninguna otra peculiaridad que te parezca interesante.\n");
    AddDetail(({"empalizada","cerca"}),"Corta el paso entre los cultivos y "
        "el camino de la granja para que no se cuele ning�n animal o persona.\n");
    AddExit("norte", SHERALD("campo/labranza06"));
    AddExit("oeste", SHERALD("campo/labranza09"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
