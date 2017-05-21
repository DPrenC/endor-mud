/****************************************************************************
Fichero: arena8.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Hacia el sur, ves un saliente natural que se adentra en el lago, "
               "formando una ligera pendiente que muere en la orilla del mismo.\n");
    AnadeDetalleLago("sur");


    AddExit("oeste","arena7");
    AddExit("norte","arena10");
    AddExit("noroeste","arena9");
    AddExit("sur","arena6");
    AddExit("suroeste","arena5");

}


