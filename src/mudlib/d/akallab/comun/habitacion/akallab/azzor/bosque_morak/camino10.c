/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino10.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntShort("un claro en el camino a través del bosque de Morak");
    SetIntLong("El camino que conduce a la cantera se une aquí al camino "
        "principal que atraviesa el bosque de Morak. Este camino parte de "
        "este calvero en el bosque hacia el noroeste, hacia la base de las "
        "montañas donde se encuentra la cantera. El calvero que tienes ante "
        "ti es un claro en el bosque que se abre hacia el sureste de aquí. "
        "El camino que atraviesa el bosque se encuentra al otro lado del "
        "calvero.\n");
    AddDetail(({"claro","calvero"}),"El calvero o claro, es una extensión de "
        "pradera sin árboles en medio del bosque. El camino se divide en dos "
        "al sur de aquí.\n");
    AddExit("oeste",BOSQUE_MORAK("bosque08"));
    AddExit("noroeste",BOSQUE_MORAK("camino11"));
    AddExit("sur",BOSQUE_MORAK("camino03"));
    AddExit("sudeste",BOSQUE_MORAK("camino04"));
}
