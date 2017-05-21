/****************************************************************************
Fichero: /d/simauria/comun/objeto/otrobetua/fuente.c
Autor: Lug y Yalin
Fecha: 07/05/2007
Descripci�n: Fuente para la parada de diligencia en Gorat
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una peque�a fuente, apenas un pilar de piedra con un ca�o de "
        "metal que deja caer su chorro en un brocal de piedra en el suelo.\n");
    SetNoGet("Buen intento... Prueba otra vez.\n");
}

