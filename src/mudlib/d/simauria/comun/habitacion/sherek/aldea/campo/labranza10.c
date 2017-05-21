/* Archivo:         labranza10.c
Autor:           Yalin y Lug
Descripci�n:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este est� la pared trasera de un "
        "establo. En las dem�s direcciones contin�a la plantaci�n\n");
    AddDetail (({"pared"}),"Es una pared construida con grandes maderos.\n");
    AddDetail(({"establo"}),"s�lo ves la pared trasera. No tiene nada m�s de "
        "inter�s.\n");
    AddExit("norte", SHERALD("campo/labranza09"));
    AddExit("sur", SHERALD("campo/labranza11"));
    AddExit("oeste", SHERALD("campo/labranza14"));
}
