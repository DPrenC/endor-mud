/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera254.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("este",SHERCAN("fondo/cantera253"));
    AddExit("sur",SHERCAN("fondo/cantera244"));
    AddExit("norte",SHERCAN("fondo/cantera264"));
    AddExit("nordeste",SHERCAN("fondo/cantera263"));
    pongo();
}
