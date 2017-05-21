/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/sherek/aldea/fuente.c
Autor: Lug y Yalin
Fecha: 16/05/2007
Descripci�n: Fuente para la plaza de Sloch.
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una peque�a fuente, apenas un pilar de piedra con un ca�o de "
        "metal que deja caer su chorro en un brocal de piedra en el suelo.\n");
    SetNoGet("Tranquil�zate, no te vaya a dar algo.\n");
}

