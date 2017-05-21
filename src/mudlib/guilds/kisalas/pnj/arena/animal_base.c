/****************************************************************************
Fichero: animal_base
Autor: Kastwey
Fecha: 01/03/2006
Descripción: El animal base para la arena de las Kisalas. Aquí añado el
WalkZones, y cualquier cosa que puedan tener en común en un futuro.
****************************************************************************/


#include "path.h"

inherit NPC;

create()
{
    ::create();
   AddWalkZones(AM_ARENA(""));
}
