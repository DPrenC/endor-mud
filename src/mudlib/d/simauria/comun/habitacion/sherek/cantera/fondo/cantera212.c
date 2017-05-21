/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera212.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("nordeste",SHERCAN("fondo/cantera221"));
    AddExit("oeste",SHERCAN("fondo/cantera213"));
    AddExit("norte",SHERCAN("fondo/cantera222"));
    pongo();
}
