/*
DESCRIPCION  : patio
FICHERO      : patio16.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
    ::create();
    SetIntShort("un patio");
    SetIntLong("Estás en un patio dentro de la fortaleza. Antiguamente, esta parte "
    "del castillo se usaba para el adiestramiento de la tropa. Ahora ya no es más "
    "que un lugar de tránsito dentro del recinto .\n");
    AddExit("sur",ROOMFF("despens2"));
    AddExit("oeste",ROOMFF("patio05"));
    //AddExit("este",ROOMFF("banco"));
    AddExit("norte",ROOMFF("despens3"));
    AnyadirPnjs();
  }
