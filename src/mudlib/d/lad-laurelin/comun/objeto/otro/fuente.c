/****************************************************************************
Fichero: /d/lad-laurelin/comun/objeto/otro/fuente.c
Autor: Lug y Yalin
Fecha: 08/05/2007
Descripción: Fuente para la ciudad de Atbalnin
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una pequeña fuente incrustada en el hueco del árbol. Te "
        "preguntas como metieron las tuberías por el tronco...\n");
    SetNoGet("¿Quieres ir por el mundo con un árbol a cuestas?\n");
}

