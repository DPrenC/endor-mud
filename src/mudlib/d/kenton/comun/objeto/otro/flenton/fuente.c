/****************************************************************************
Fichero: /d/kenton/comun/objeto/otro/flenton/fuente.c
Autor: Lug y Yalin
Fecha: 10/05/2007
Descripción: Fuente para la plaza de Flenton
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una fuente hecha de piedra.\nEn el centro hay una estatua, "
        "y de su base salen numerosos chorros de agua.\n");
    SetNoGet("¿Y qué iba a hacer la estatua sin su fuente?\n");
}

