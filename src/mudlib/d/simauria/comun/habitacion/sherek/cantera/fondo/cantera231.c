/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera231.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
    ::create();
    AddExit("oeste",SHERCAN("fondo/cantera232"));
    AddExit("norte",SHERCAN("fondo/cantera241"));
    AddExit("sur",SHERCAN("fondo/cantera221"));
    pongo();
}
