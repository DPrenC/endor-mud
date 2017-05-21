/****************************************************************************
Fichero: khled.c
Autor: Ratwor
Fecha: 18/11/2006
Descripción: el tendero de la tienda de los guardabosques.
****************************************************************************/



#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Khled", "humano", ([GC_GUARDABOSQUES:25]), GENDER_MALE);
    AddId(({"khled", "tendero", "Khled", "viejo"}));
    SetShort("el viejo Khled");
    SetLong("Khled es un viejo humano, retirado ya del gremio por su avanzada edad.\n"
        " Por su barba blanca y su abundancia de arrugas, puede superar perfectamente"
        " los 80 años, de los cuales, la mayor parte de ellos ha sido Guardabosques,"
        " pero actualmente, sin nada mejor que hacer, se encarga de la tienda para "
        "abastecer, de armas y demás enseres, a los miembros del gremio y demás "
        "visitantes.\n");
    SetAlign(350);
    SetSmell("Huele a pieles y grasas de las armas.\n");
    AddSubDetail("barba", "Es muy blanca y larga.\n");
    AddSubDetail(({"arruga","arrugas"}), "Distintas arrugas le adornan la cara, dándole"
        " más edad de la que puede aparentar.\n");
    SetShrugMsg("Khled dice: tengo ya mucha edad para recordar cosas.\n");
}
