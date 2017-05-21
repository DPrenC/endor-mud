/*
DESCRIPCION  : patio
FICHERO      : patio06.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
    ::create();
    SetIntShort("un patio");
    SetIntLong("Estás en un patio dentro de la fortaleza. Antiguamente, esta parte "
    "del castillo se usaba para el adiestramiento de la tropa. Ahora ya no es más que "
    "un lugar de tránsito dentro del recinto . Del oeste te llega el ruido de una "
    "taberna.\n");
    AddExit("norte",ROOMFF("patio15"));
    AddExit("este",ROOMFF("armeria"));
    AddExit("sur",ROOMFF("plaza04"));
    AddExit("oeste",ROOMFF("pub1"));
    AddDoor("oeste", "la puerta de la taberna",
    "Es una puerta de madera que da entrada a la taberna de la fortaleza.\n",
    ({"puerta", "puerta de la taberna", "puerta del oeste"}));
    AddDoor("este", "una puerta", "Es una sencilla puerta de madera sin nada de particular.\n",
        ({"puerta", "puerta de madera", "puerta sencilla"}));
    AnyadirPnjs();
  }
