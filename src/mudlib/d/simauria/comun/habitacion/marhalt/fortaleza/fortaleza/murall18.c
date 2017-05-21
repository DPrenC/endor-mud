/*
DESCRIPCION  : muralla
FICHERO      : murall18.c
MODIFICACION : 16-07-00 [Maler] Creacion
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
  AddExit("nordeste",ROOMFF("murall20"));
  AddExit("suroeste",ROOMFF("torre05"));
  AnyadirPnjs();
  }