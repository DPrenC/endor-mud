/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq044.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq038"));
  AddExit("norte",ROOMFB("bosq037"));
  AddExit("noroeste",ROOMFB("bosq036"));
  AddExit("sur",ROOMFB("bosq049"));
  AddExit("sudeste",ROOMFB("bosq050"));
  AnyadirPnjs();
  }
