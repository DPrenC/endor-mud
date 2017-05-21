/*
DESCRIPCION  : plaza
FICHERO      : plaza04.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("una plaza");
  SetIntLong(W("Estás en una inmensa plazoleta central, dentro del castillo. "
  "Al no haberse cuidado, la vegetación que antes adornaba este lugar ha crecido "
  "descontrolada, dificultando el paso e invadiendo el camino.\n"));
  AddExit("norte",ROOMFF("patio06"));
  AddExit("sur",ROOMFF("fuente"));
  AddExit("sudeste",ROOMFF("plaza03"));
  AddExit("suroeste",ROOMFF("plaza02"));
  AnyadirPnjs();
  AddDetail("vegetacion","La espesa vegetacion colapsa esta zona.\n");
  }
