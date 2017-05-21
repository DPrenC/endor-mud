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
  SetIntLong(W("Estás en la primera planta de la muralla. Aquí se almacenan "
  "todo tipo de artefactos para repeler asaltos a la fortaleza. Es difícil no darse "
  "cuenta de que están en perfecto estado, y listos para su uso.\n"));
  AddExit("noroeste",ROOMFF("murall12"));
  AddExit("sudeste",ROOMFF("torre03"));
  AddDetail("artefactos","Aceite, piedras, y todo tipo de objetos lanzables.\n");
  AnyadirPnjs();
  }