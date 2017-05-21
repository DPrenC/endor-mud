/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq009.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq016"));
  AddExit("suroeste",ROOMFB("bosq015"));
  AddExit("norte",ROOMFB("bosq003"));
  AnyadirPnjs();
  }
