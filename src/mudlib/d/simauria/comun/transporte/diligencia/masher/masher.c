/****************************************************************************
Fichero: /d/simauria/comun/transporte/diligencia/masher/masher.c
Autor: Lug y Yalin
Fecha: 01/08/2006
Descripción: La diligencia Masher, que hace el recorrido entre Nandor y Sloch
****************************************************************************/

#include "path.h"
#include <properties.h>
inherit STAGECOACH;

create()
{
    seteuid(getuid(TO));
    ::create();
    SetShort("La diligencia Masher");
    SetLong("Esta es la destartalada diligencia que une la ciudad de Nandor "
        "con la aldea de Sloch, en los dominios de Sherek.\n");
    Set(P_NOGET, "Claro, y te la cuelgas al hombro...\n");
    Set(P_NOSELL, "¿Ya tienes el título de propiedad?\n");
    SetDnombre("masher");
    SetDhabitacion("/d/simauria/comun/transporte/diligencia/masher/intmasher");
    SetDmensajes_entrar(({"entra en la diligencia","sube al masher","Subes al masher"}));
    SetDmensaje_llega("La diligencia Masher llega gimiendo y traqueteando.\n");
    SetDmensaje_seva("La diligencia Masher se pierde entre ruido y polvo.\n");
    SetRecorrido("/d/simauria/comun/transporte/diligencia/masher/masher.txt");
    SetInicio(MARH("nandor/calle42s"));
    SetParadas(({({MARH("nandor/calle42s"),30,1000}),
        ({CNSH("camino99"),30,1000})}));
    SetDestinos(({"Nandor","Sloch"}));
    SetDconductor(PNJ("diligencia/masher"));
    SetNombreConductor("Rayshen");
}

