/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq059.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq054"));
  AddExit("sudeste",ROOMFB("bosq067"));
  AddExit("suroeste",ROOMFB("bosq065"));
  AnyadirPnjs();
  }
