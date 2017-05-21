/****************************************************************************
Fichero: arena1.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Al norte de aquí puedes ver la entrada a lo que parece un pasillo "
               "en el edificio del gremio, mientras que al sur, se encuentra la "
               "costa de esta isla, bañada por las malolientes aguas del lago.\n");

    AnadeDetalleEdificio("oeste");

    AddExit("este","arena9");
    AddExit("norte",AM_PASILLO("pasillo2"));
    AddExit("sur","arena4");
    AddExit("sudeste","arena7");
    AddExit("suroeste","arena3");


}


