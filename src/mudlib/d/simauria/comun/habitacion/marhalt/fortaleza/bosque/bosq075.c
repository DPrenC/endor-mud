/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq075.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq066"));
  AddExit("suroeste",ROOMFB("bosq084"));
  AddExit("sudeste",ROOMFB("bosq086"));
  AnyadirPnjs();
  }
