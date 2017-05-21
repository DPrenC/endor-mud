/*
DESCRIPCION  : plaza
FICHERO      : plaza02.c
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
  AddExit("oeste",ROOMFF("patio04"));
  AddExit("este",ROOMFF("fuente"));
  AddExit("nordeste",ROOMFF("plaza04"));
  AddExit("sudeste",ROOMFF("plaza01"));
  AnyadirPnjs();
  AddDetail("vegetacion","La espesa vegetacion colapsa esta zona.\n");
  }
