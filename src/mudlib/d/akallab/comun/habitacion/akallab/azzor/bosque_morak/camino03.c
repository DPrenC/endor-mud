/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino03.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("un claro en el camino a través del bosque de Morak");
    SetIntLong("Te encuentras en el extremo suroeste de un calvero en medio "
        "del bosque, un gran claro en el que no hay árboles. Del camino "
        "principal, que va de suroeste a este, se desvía un sendero hacia el "
        "norte, hacia la cantera que hay al pie de las montañas de la "
        "cordillera de Kova.\n");
    AddDetail(({"claro","calvero"}),"El calvero o claro, es una extensión de "
        "pradera sin árboles en medio del bosque. El camino se divide en dos "
        "al norte de aquí.\n");
    AddExit("este",BOSQUE_MORAK("camino04"));
    AddExit("norte",BOSQUE_MORAK("camino10"));
    AddExit("suroeste",BOSQUE_MORAK("camino02"));
    AddExit("oeste",BOSQUE_MORAK("bosque05"));
}
