/****************************************************************************
Fichero: arena17.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Esta parte linda hacia el sur con una de las paredes del edificio "
               "del gremio, mientras que al norte, ves el final de la isla. Al "
               "este, la tierra desciende, formándose un estrecho paso que "
               "desemboca en las aguas del lago.\n");


    AnadeDetalleEdificio("sur");


    AddExit("este","arena18");
    AddExit("norte","arena19");
    AddExit("nordeste","arena20");



}


