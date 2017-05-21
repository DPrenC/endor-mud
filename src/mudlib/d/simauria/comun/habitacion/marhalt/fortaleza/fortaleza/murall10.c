/*
DESCRIPCION  : muralla
FICHERO      : murall10.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("la muralla");
  SetIntLong(W("Est�s en la primera planta de la muralla. Aqu� se almacenan "
  "todo tipo de artefactos para repeler asaltos a la fortaleza. Es dif�cil no darse "
  "cuenta de que est�n en perfecto estado, y listos para su uso.\n"));
  AddExit("noroeste",ROOMFF("murall12"));
  AddExit("sudeste",ROOMFF("torre03"));
  AddDetail("artefactos","Aceite, piedras, y todo tipo de objetos lanzables.\n");
  AnyadirPnjs();
  }