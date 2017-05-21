/****************************************************************************
Fichero: arena2.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
        SetIntLong("Al norte, puedes ver una de las paredes del edificio "
                   "del gremio, mientras que al oeste, divisas el embarcadero "
                   "que te permite coger el bote para atravesar las aguas del "
                   "lago. Al sur, los últimos árboles acaban casi al borde del "
                   "agua... Con lo sucia que está, lo sorprendente es que "
                   "crezcan árboles aquí.\n");


    AnadeDetalleEdificio("norte");

    AddExit("oeste",LAGO("embarcadero"));
    AddExit("este","arena3");
}


