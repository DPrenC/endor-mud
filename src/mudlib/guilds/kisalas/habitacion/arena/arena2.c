/****************************************************************************
Fichero: arena2.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
        SetIntLong("Al norte, puedes ver una de las paredes del edificio "
                   "del gremio, mientras que al oeste, divisas el embarcadero "
                   "que te permite coger el bote para atravesar las aguas del "
                   "lago. Al sur, los �ltimos �rboles acaban casi al borde del "
                   "agua... Con lo sucia que est�, lo sorprendente es que "
                   "crezcan �rboles aqu�.\n");


    AnadeDetalleEdificio("norte");

    AddExit("oeste",LAGO("embarcadero"));
    AddExit("este","arena3");
}


