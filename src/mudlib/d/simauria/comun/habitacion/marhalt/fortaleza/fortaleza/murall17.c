/*
DESCRIPCION  : muralla
FICHERO      : murall17.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("la muralla");
  SetIntLong(W("Est�s en la segunda planta de la muralla. Se puede caminar por su interior, "
  "y cada cierto tiempo observas unos ventanucos dise�ados para disparar desde el interior con  "
  "poco riesgo.\n"));
  AddExit("noroeste",ROOMFF("murall19"));
  AddExit("sudeste",ROOMFF("torre05"));
  AnyadirPnjs();
  }