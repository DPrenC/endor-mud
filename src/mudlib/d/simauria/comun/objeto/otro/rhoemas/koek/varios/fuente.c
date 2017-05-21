/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/rhoemas/koek/varios/fuente.c
Autor: Lug y Yalin
Fecha: 02/05/2007
Descripción: Fuente para la plaza de Koek
****************************************************************************/

#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Entre los pies de la estatua, una pequeña columna sostiene una "
        "pila circular, de cuyo centro brota un surtidor de agua.\n");
    SetNoGet("¿Y no quieres llevarte también la plaza?\n");
}

