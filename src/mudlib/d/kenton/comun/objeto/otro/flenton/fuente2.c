/****************************************************************************
Fichero: /d/kenton/comun/objeto/otro/flenton/fuente2.c
Autor: Lug y Yalin
Fecha: 06/06/2007
Descripción: Fuente para la plaza secundaria de Flenton
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una fuente hecha de piedra. De ella salen numerosos chorros "
        "de agua.\n");
    SetNoGet("La fuente está muy bien donde está.\n");
}

