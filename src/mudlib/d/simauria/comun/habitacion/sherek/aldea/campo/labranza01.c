/* Archivo        labranza01.c
Autor:         Yalin y Lug
Fecha:         14/05/2006
Descripci�n:   campos de cultivo de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("campo/huerta");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte puedes ver una empalizada que "
        "separa los cultivos de los pastos y, en las dem�s direcciones, "
        "contin�an los campos de cultivo.\n");
    SetIntNoise("Puedes o�r el piar de algunos pajarillos y voces de "
        "personas a lo lejos.\n");
    SetIntSmell("Huele a tierra removida.\n");
    AddDetail(({"empalizada","cerca"}), "Se trata de una vaya de varios pies "
        "de alto que separa los cultivos de los pastos para evitar que los "
        "animales puedan comerse las cosechas.\n");
    AddExit("oeste", SHERALD("campo/labranza00"));
    AddExit("este", SHERALD("campo/labranza02"));
    AddExit("sur", SHERALD("campo/labranza04"));
}
