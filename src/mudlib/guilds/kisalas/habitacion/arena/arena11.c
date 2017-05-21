/****************************************************************************
Fichero: arena11.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Hacia el oeste puedes ver una de las paredes del edificio "
               "del gremio, y al este, la costa oriental de la isla.\n");

    AnadeDetalleEdificio("oeste");


    AddExit("este","arena12");
    AddExit("norte","arena13");
    AddExit("nordeste","arena14");
    AddExit("sur","arena9");
    AddExit("sudeste","arena10");

}


