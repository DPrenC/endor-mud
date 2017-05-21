/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam18.c
Autor: Yalin
Fecha: 04/07/2009 23:07
Descripción: Camino de montaña hacia la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"Aquí el camino presenta una mayor inclinación, salvando el último "
        "tramo abrupto antes de al canzar la cima.\nDesde tu posición puedes ver ya el frontón del "
        "imponente edificio de la abadía, al norte, mientras que hacia el sur, el camino se pierde en "
        "dirección al valle.\n");
    AddExit("norte", SHERAB("camino/meseta"));
    AddExit("sur", SHERAB("camino/cam17"));
}
