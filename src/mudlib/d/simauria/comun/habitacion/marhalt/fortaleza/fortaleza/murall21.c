/*
DESCRIPCION  : muralla
FICHERO      : murall21.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("la muralla");
  SetIntLong(W("Estás en la segunda planta de la muralla. Se puede caminar por su interior, "
  "y cada cierto tiempo observas unos ventanucos diseñados para disparar desde el interior con  "
  "poco riesgo.\n"));
  AddExit("noroeste",ROOMFF("murall23"));
  AddExit("sudeste",ROOMFF("murall19"));
  AnyadirPnjs();
  }