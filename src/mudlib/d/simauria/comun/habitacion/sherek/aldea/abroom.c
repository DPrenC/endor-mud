/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/abroom.c
Autor: Lug y Yalin
Fecha: 13/01/2007
Descripción: Base de habitación al aire libre para la aldea
****************************************************************************/
#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetIndoors(0);
}

