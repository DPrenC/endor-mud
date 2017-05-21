/*
DESCRIPCION  : patio
FICHERO      : patio05.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
#include <properties.h>
#include <door.h>
#include <materials.h>
#include <sounds.h>
#include <scheduler.h>


inherit ROOMFF("fortalez");
create()
{
    ::create();
    SetIntShort("un patio");
    SetIntLong("Estás en un patio dentro de la fortaleza. Antiguamente, esta parte "
    "del castillo se usaba para el adiestramiento de la tropa. Ahora ya no es más que "
    "un lugar de tránsito dentro del recinto .\n");
    AddExit("sur",ROOMFF("despens1"));
    AddExit("oeste",ROOMFF("plaza03"));
    AddExit("este",ROOMFF("patio16"));
    AddExit("norte",ROOMFF("tienda"));
    AddDoor("norte", "la puerta de la tienda",
    "Es una puerta que da entrada a la tienda.\n",
    ({"puerta", "puerta de la tienda", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AnyadirPnjs();
  }
