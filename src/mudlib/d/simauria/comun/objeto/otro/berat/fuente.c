/****************************************************************************
Fichero: /d/simauria/comun/objeto/otro/berat/fuente.c
Autor: Lug y Yalin
Fecha: 02/05/2007
Descripción: Fuente para la calle principal de Berat
****************************************************************************/

#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una rudimentaria fuente, apenas una pileta de piedra adosada a la pared de la "
    "fonda, con un caño de metal que sale de la propia pared.\n");
    AddId(({"fuente","pileta","caño","canyo"}));
    SetNoGet("Pruébalo, si te crees capaz.\n");
}

