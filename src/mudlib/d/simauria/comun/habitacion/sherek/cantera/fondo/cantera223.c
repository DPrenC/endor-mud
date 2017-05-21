/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera223.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("este",SHERCAN("fondo/cantera222"));
    AddExit("suroeste",SHERCAN("fondo/cantera214"));
    AddExit("sur",SHERCAN("fondo/cantera213"));
    AddExit("norte",SHERCAN("fondo/cantera233"));
    pongo();
}
