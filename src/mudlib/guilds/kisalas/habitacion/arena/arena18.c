/****************************************************************************
Fichero: arena18.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();

    SetIntLong("Aquí, la tierra comienza a inclinarse hacia abajo en dirección norte, "
    " mientras que al este y al oeste mantienen su elevación original, creando un "
    "estrecho paso que desemboca en las aguas del lago.\n");

    AddDetail(({"paso", "pequeño paso","playa"}),
              "La configuración del terreno, hace que en esta parte se forme un "
              "estrecho paso descendente que muere en el lago, mientras que al este "
              "y al oeste, la tierra cae desde varios metros hasta las aguas.\n");

    AnadeDetalleLago("norte");
    AnadeDetalleEdificio("sur");

    AddExit("oeste","arena17");
    AddExit("este","arena15");
    AddExit("norte","arena20");
    AddExit("noroeste","arena19");
    AddExit("sudeste","arena13");

}


