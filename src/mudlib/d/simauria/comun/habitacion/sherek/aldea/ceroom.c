/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/ceroom.c
Autor: Lug y Yalin
Fecha: 13/01/2007
Descripción: Base para las habitaciones cerradas de la aldea.
****************************************************************************/

#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetIndoors(1);
    SetIntBright(50);
}
