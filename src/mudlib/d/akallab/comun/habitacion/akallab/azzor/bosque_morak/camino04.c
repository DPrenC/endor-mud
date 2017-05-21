/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino04.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("un claro en el camino a través del bosque de Morak");
    SetIntLong("Hacia el noroeste de aquí se abre un calvero en medio del "
        "bosque de Morak, dejando paso a una pequenya pradera. Del camino "
        "principal, en el que te encuentras, se desvía un sendero hacia el "
        "noroeste, hacia la cantera que hay al pie de las montañas y de la "
        "que has oído hablar. El camino continúa de este a oeste.\n");
    AddDetail(({"claro","calvero"}),"El calvero o claro, es una extensión de "
        "pradera sin árboles en medio del bosque. El camino se divide en dos "
        "al oeste de aquí.\n");
    AddExit("norte",BOSQUE_MORAK("bosque07"));
    AddExit("este",BOSQUE_MORAK("camino06"));
    AddExit("sur",BOSQUE_MORAK("bosque06"));
    AddExit("oeste",BOSQUE_MORAK("camino03"));
    AddExit("noroeste",BOSQUE_MORAK("camino10"));
}
