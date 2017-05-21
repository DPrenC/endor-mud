/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq097.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq087"));
  AddExit("este",ROOMFB("bosq098"));
  AddExit("sur",ROOMFB("bosq106"));
  AnyadirPnjs();
  }
