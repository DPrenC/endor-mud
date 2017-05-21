/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera253.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("fondo/cantera262"));
    AddExit("oeste",SHERCAN("fondo/cantera254"));
    AddExit("sur",SHERCAN("fondo/cantera243"));
    AddExit("norte",SHERCAN("fondo/cantera263"));
    pongo();
}
