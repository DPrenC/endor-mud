/*
DESCRIPCION  : patio
FICHERO      : patio03.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("un patio");
  SetIntLong(W("Estás en un patio dentro del castillo. Antiguamente, esta parte del castillo se "
  "usaba para el adiestramiento de la tropa. Ahora ya no es más que un lugar de tránsito dentro "
  "de la fortaleza.\n"));
  AddExit("sur",ROOMFF("patio02"));
  AddExit("norte",ROOMFF("plaza01"));
  AddExit("este",ROOMFF("estab04"));
  AddExit("oeste",ROOMFF("estab03"));
  AnyadirPnjs();
  }
