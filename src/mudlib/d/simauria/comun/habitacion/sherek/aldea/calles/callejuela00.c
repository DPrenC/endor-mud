/* Archivo        callejuela00.c
   Autor:         Yalin y Lug
   Fecha:         05/05/2006
   Descripción:   Callejuela que lleva al camino del labadero(proyecto)
*/


#include "path.h"
inherit SHERALD("abroom");

create ()
{
    ::create();
    SetIntShort("una callejuela en la aldea de Sloch");
    SetIntLong("Caminas por una estrecha callejuela de guijarros que conecta la plaza de la aldea "
    "con el camino que baja al lavadero que hay en la orilla del río. Al norte puedes ver el muro "
    "de una casa, al sur tienes un granero, al este está la plazoleta de la aldea y hacia el "
    "oeste prosigue la callejuela.\n");
    SetIntNoise("Oyes el parloteo de los aldeanos.\n");
    SetIntSmell("Huele a bosta de vaca.\n");
    AddDetail(({"casa", "norte"}), "Ves el muro de una casa.\n");
    AddDetail(({"muro"}) , "Se trata de un muro de mampostería encalado: "
        "como los de toda la aldea.\n");
    AddDetail(({"suelo", "camino"}), "El suelo está formado por pequeños guijarros incrustados "
        "en la tierra endurecida.\n");
    AddDetail(({"sur", "granero"}), "Es un edificio bajo, construido con gruesos troncos de "
        "madera en el que se almacenan los sacos de granos pertenecientes "
        "a la comunidad.\n");
    AddExit("este", SHERALD("calles/plazoleta"));
    AddExit("oeste", SHERALD("calles/callejuela01"));
    AddExit("sur", SHERALD("casas/granero00"));
}
