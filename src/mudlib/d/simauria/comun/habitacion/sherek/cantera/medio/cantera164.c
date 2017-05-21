/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/mediocantera164.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripción: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
inherit SHERCAN("medio/cantera1");

create()
{
    ::create();
    AddExit("este",SHERCAN("medio/cantera163"));
    AddExit("sur",SHERCAN("medio/cantera154"));
    pongo();
}
