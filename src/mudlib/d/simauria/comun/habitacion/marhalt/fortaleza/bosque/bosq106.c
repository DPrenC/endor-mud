/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq106.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq097"));
  AddExit("nordeste",ROOMFB("bosq098"));
  AddExit("suroeste",ROOMFB("bosq114"));
  AddExit("sudeste",ROOMFB("bosq116"));
  AnyadirPnjs();
  }
