/*
DESCRIPCION  : patio
FICHERO      : patio10.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("un patio");
  SetIntLong(W("Est�s en un patio dentro del castillo. Antiguamente, esta parte del castillo se "
  "usaba para el adiestramiento de la tropa. Ahora ya no es m�s que un lugar de tr�nsito dentro "
  "de la fortaleza.\n"));
  AddExit("sur",ROOMFF("patio07"));
  AddExit("suroeste",ROOMFF("patio11"));
  AnyadirPnjs();
  }
