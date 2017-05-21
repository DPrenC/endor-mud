/****************************************************************************
Fichero: arena13.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("En esta parte, los árboles y la vegetación se espesan de tal "
               "modo que te es imposible avanzar en dirección oeste. Al este "
               "puedes ver como la isla acaba en el lago, mientras que al norte "
               "y al sur el bosque continúa.\n");

    AnadeDetalleLago("este");

    AddExit("este","arena14");
    AddExit("norte","arena15");
    AddExit("nordeste","arena16");
    AddExit("noroeste","arena18");
    AddExit("sur","arena11");
    AddExit("sudeste","arena12");

}


