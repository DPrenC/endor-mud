/****************************************************************************
Fichero: /d/lad-laurelin/comun/objeto/otro/faeria/fuente.c
Autor: Lug y Yalin
Fecha: 08/05/2007
Descripción: Fuente para la calle principal de Siempreunidos
****************************************************************************/
#include "path.h"
inherit "/obj/fountain";

create()
{
    ::create();
    SetShort("una fuente");
    AddId(({"fuente","estatua","elfo"}));
    SetLong("Sobre un pedestal en mitad de la calle, observas la figura de "
        "un elfo ataviado con larga túnica y corona. De su boca surge un "
        "gran chorro de agua.\n");
// no pongo NoGet(), dejo el de la room
}

