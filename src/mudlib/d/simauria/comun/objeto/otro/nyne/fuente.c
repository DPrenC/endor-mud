/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/nyne//fuente.c
Autor: Lug y Yalin
Fecha: 02/05/2007
Descripción: Fuente en el manantial de Nyne
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una fuente con un largo caño de piedra de la cual mana un "
        "fino chorro de agua fresca y cristalina que cae en el estanque.\n");
    SetNoGet("¿Con estanque o sin estanque...\n");
}
