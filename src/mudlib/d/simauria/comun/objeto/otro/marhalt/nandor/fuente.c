/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/marhalt/nandor/fuente.c
Autor: Lug y Yalin
Fecha: 02/05/2007
Descripci�n: Fuente para la plaza de Nandor
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una peque�a fuente, apenas un pilar de piedra con un ca�o de "
        "metal que deja caer su chorro en un brocal de piedra en el suelo.\n");
    SetNoGet("Desde luego, los hay bestias.\n");
}

