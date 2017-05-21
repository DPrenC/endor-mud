/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera244.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("este",SHERCAN("fondo/cantera243"));
    AddExit("sur",SHERCAN("fondo/cantera234"));
    AddExit("norte",SHERCAN("fondo/cantera254"));
    AddExit("suroeste",SHERCAN("fondo/cantera235"));
    pongo();
}
