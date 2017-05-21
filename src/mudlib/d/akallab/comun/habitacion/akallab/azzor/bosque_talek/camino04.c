/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino04.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Continúas avanzando por el interior del bosque de Talek, "
        "siguiendo el Camino del Este. Este camino continúa hacia el este y "
        "hacia el noroeste. En el suelo del camino puedes apreciar las "
        "huellas dejadas por los carros que suelen circular por él. Sopla "
        "una agradable brisa desde el este.\n");
    AddDetail(({"huellas"}),"Puedes observar las huellas de los carros y "
        "diligencias que pasan por aquí en el camino. Supones que este debe "
        "ser un camino bastante transitado.\n");
    AddExit("este",BOSQUE_TALEK("camino05"));
    AddExit("noroeste",BOSQUE_TALEK("camino03"));
    AddExit("norte",BOSQUE_TALEK("bosque31"));
    AddExit("sur",BOSQUE_TALEK("bosque19"));
}
