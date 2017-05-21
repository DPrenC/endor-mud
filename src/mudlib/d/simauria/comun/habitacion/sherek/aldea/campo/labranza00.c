/* Archivo        labranza00.c
Autor:         Yalin y Lug
Fecha:         14/05/2006
Descripción:   campos de cultivo de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("campo/huerta");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte puedes ver la casa de los "
        "administradores, al oeste está la calle que cruza la granja y, en "
        "las demás direcciones, continúan los campos de cultivo.\n");
    SetIntNoise("Puedes oír el piar de algunos pajarillos y voces de "
        "personas a lo lejos.\n");
    SetIntSmell("Huele a tierra removida.\n");
    AddDetail(({"casa","casa de los administradores"}),"es una casa bastante "
        "grande construida en piedra y pintada de blanco. Tiene planta baja "
        "y piso superior y está ligeramente alzada sobre el nivel del suelo, "
        "lo que te indica que aquí suele haber inundaciones.\n");
    AddDetail(({"calle"}),"Es la calle que cruza la granja.\n");
    AddExit("oeste", SHERALD("granja/granja01"));
    AddExit("este", SHERALD("campo/labranza01"));
    AddExit("sur", SHERALD("campo/labranza03"));
    AddItem(PNJ("sherek/aldea/aldeanoc"), REFRESH_DESTRUCT,2);
}
