/****************************************************************************
Fichero: animal_base
Autor: Kastwey
Fecha: 01/03/2006
Descripci�n: El animal base para la arena de las Kisalas. Aqu� a�ado el
WalkZones, y cualquier cosa que puedan tener en com�n en un futuro.
****************************************************************************/


#include "path.h"

inherit NPC;

create()
{
    ::create();
   AddWalkZones(AM_ARENA(""));
}
