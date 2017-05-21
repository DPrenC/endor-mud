/* Archivo: /d/simauria/comun/pnj/abadia/aldeanog.c
* Descripción: Aldeano trabajando en la granja.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit PNJ("sherek/aldea/aldeano");

create()
{
    ::create();
    SetShort(QueryShort()+"granjero");
    SetLong(QueryLong()+"Ahora está cumpliendo su turno de trabajo en la granja "
        "cuidando de los animales y limpiando los establos.\n");
    AddId(({"aldeano","granjero"}));
    SetGoChance(90);
    AddWalkZones(SHERALD("granja"));
}
