/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/aldea/oveja.c
Autor: Lug y Yalin
Fecha: 16/01/2007
Descripción: Ovejas para la granja.
****************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

string color;

create()
{
    ::create();
    SetStandard("una oveja","oveja",10+d6(),GENERO_FEMENINO);
    switch (d3())
    {
        case 1:
            color = "blanca";
        break;
        case 2:
            color = "negra";
        break;
        case 3:
            color = "manchada";
        break;
    }
    SetShort("una oveja "+color);
    SetLong("Es una oronda oveja "+color+". Está algo nerviosa porque hoy "
        "no la han sacado a pacer al campo.\n");
    AddId("oveja");
    SetWeight(75000);
    SetNoGet("La oveja se escabuye asustada.\n");
    InitChats(5,
        ({"La oveja bala tristemente.\n",
        "La oveja mordisquea la alfalfa.\n",
        "La oveja te mira desconfiada.\n",
    "la oveja Se rasca con la pared.\n"}));
}
