/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/fondo/cantera232.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("fondo/cantera2");

create()
{
     ::create();
    AddExit("este",SHERCAN("fondo/cantera231"));
    AddExit("noroeste",SHERCAN("fondo/cantera243"));
    AddExit("sur",SHERCAN("fondo/cantera222"));
    AddExit("nordeste",SHERCAN("fondo/cantera241"));
    pongo();
}
