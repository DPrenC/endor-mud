/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/abroom.c
Autor: Lug y Yalin
Fecha: 13/01/2007
Descripci�n: Base de habitaci�n al aire libre para la aldea
****************************************************************************/
#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetIndoors(0);
}

