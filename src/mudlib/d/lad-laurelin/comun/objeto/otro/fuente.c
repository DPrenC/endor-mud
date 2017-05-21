/****************************************************************************
Fichero: /d/lad-laurelin/comun/objeto/otro/fuente.c
Autor: Lug y Yalin
Fecha: 08/05/2007
Descripci�n: Fuente para la ciudad de Atbalnin
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una peque�a fuente incrustada en el hueco del �rbol. Te "
        "preguntas como metieron las tuber�as por el tronco...\n");
    SetNoGet("�Quieres ir por el mundo con un �rbol a cuestas?\n");
}

