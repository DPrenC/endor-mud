/****************************************************************************
Ficero: arena19.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Estás en el final de la isla, en la costa nordeste, justo ante las "
               "aguas del lago Zinn. Por esta parte, la tierra acaba abruptamente "
               "varios metros por encima del agua. seguramente, los árboles que crecen "
               "hasta el borde de la misma han impedido que se erosione y se "
               "forme una pendiente hasta el lago, como puedes ver al oeste.\n");


    AnadeDetalleLago("norte");

    AddExit("este","arena20");
    AddExit("sur","arena17");
    AddExit("sudeste","arena18");

}


