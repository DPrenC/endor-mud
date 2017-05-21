/* Archivo:         labranza11.c
Autor:           Yalin y Lug
Descripci�n:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el sur puedes ver la pared trasera del "
        "granero de la granja, hacia el este est� la pared trasera de un "
        "establo. En las dem�s direcciones contin�a la plantaci�n\n");
    AddDetail (({"pared"}),"Se trata de una simple pared construida con "
        "grandes maderos.\n");
    AddDetail(({"granero","establo"}),"s�lo ves la pared trasera. No tiene "
        "nada m�s de inter�s.\n");
    AddExit("norte", SHERALD("campo/labranza10"));
    AddExit("oeste", SHERALD("campo/labranza15"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
