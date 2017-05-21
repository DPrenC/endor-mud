/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq098.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("oeste",ROOMFB("bosq097"));
  AddExit("suroeste",ROOMFB("bosq106"));
  AddExit("sudeste",ROOMFB("bosq107"));
  AnyadirPnjs();
  }
