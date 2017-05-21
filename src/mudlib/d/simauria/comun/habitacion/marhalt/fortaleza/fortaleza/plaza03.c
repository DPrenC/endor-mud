/*
DESCRIPCION  : plaza
FICHERO      : plaza03.c
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
  AddExit("este",ROOMFF("patio05"));
  AddExit("oeste",ROOMFF("fuente"));
  AddExit("noroeste",ROOMFF("plaza04"));
  AddExit("suroeste",ROOMFF("plaza01"));
  AnyadirPnjs();
  AddDetail("vegetacion","La espesa vegetacion colapsa esta zona.\n");
  }
