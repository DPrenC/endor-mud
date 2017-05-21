/*
DESCRIPCION  : plaza
FICHERO      : plaza01.c
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
  AddExit("sur",ROOMFF("patio03"));
  AddExit("norte",ROOMFF("fuente"));
  AddExit("noroeste",ROOMFF("plaza02"));
  AddExit("nordeste",ROOMFF("plaza03"));
  AnyadirPnjs();
  AddDetail("vegetacion","La espesa vegetacion colapsa esta zona.\n");
  }
