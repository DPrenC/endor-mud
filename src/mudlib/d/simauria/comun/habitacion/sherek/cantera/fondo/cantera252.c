/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera252.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("nordeste",SHERCAN("fondo/cantera261"));
    AddExit("noroeste",SHERCAN("fondo/cantera263"));
    AddExit("suroeste",SHERCAN("fondo/cantera243"));
    AddExit("sur",SHERCAN("fondo/cantera242"));
    pongo();
}
