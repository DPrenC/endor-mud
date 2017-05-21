/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq091.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq078"));
  AddExit("sudeste",ROOMFB("bosq101"));
  AnyadirPnjs();
  }
