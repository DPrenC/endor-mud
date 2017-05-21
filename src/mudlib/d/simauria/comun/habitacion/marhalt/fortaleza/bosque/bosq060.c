/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq060.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq054"));
  AddExit("sur",ROOMFB("bosq067"));
  AddExit("suroeste",ROOMFB("bosq066"));
  AnyadirPnjs();
  }
