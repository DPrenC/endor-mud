/* Archivo        labranza00.c
Autor:         Yalin y Lug
Fecha:         14/05/2006
Descripci�n:   campos de cultivo de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("campo/huerta");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte puedes ver la casa de los "
        "administradores, al oeste est� la calle que cruza la granja y, en "
        "las dem�s direcciones, contin�an los campos de cultivo.\n");
    SetIntNoise("Puedes o�r el piar de algunos pajarillos y voces de "
        "personas a lo lejos.\n");
    SetIntSmell("Huele a tierra removida.\n");
    AddDetail(({"casa","casa de los administradores"}),"es una casa bastante "
        "grande construida en piedra y pintada de blanco. Tiene planta baja "
        "y piso superior y est� ligeramente alzada sobre el nivel del suelo, "
        "lo que te indica que aqu� suele haber inundaciones.\n");
    AddDetail(({"calle"}),"Es la calle que cruza la granja.\n");
    AddExit("oeste", SHERALD("granja/granja01"));
    AddExit("este", SHERALD("campo/labranza01"));
    AddExit("sur", SHERALD("campo/labranza03"));
    AddItem(PNJ("sherek/aldea/aldeanoc"), REFRESH_DESTRUCT,2);
}
