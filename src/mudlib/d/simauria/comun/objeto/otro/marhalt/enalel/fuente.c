/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/marhalt/enalel/fuente.c
Autor: Lug y Yalin
Fecha: 17/06/2007
Descripci�n: Fuente para la calle de Enalel
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una fuente de metal de la que sale un refrescante chorro de "
        "agua.\n");
    SetNoGet("�No encontraste nada m�s insensato que pensar?\n");
}

